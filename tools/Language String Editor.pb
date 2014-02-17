Enumeration
	#XML
	#Window
	#List
	#InfoList
	#Splitter
	#Menu
	#PopupMenu
	#Menu_Reload
	#Menu_Save
	#Menu_Quit
	#Menu_Add
	#Menu_Edit
	#Menu_Delete
	#Menu_Goto
	#Menu_Search
	#Menu_SearchNext
	#Menu_ShowReferences
	#Menu_Show_IgnoreUnused
	#Menu_Show_NotTranslated
	#Menu_Show_OK
	#Menu_Show_Unused
	#Edit_Window
	#Edit_Text1
	#Edit_Text2
	#Edit_Text3
	#Edit_ID
	#Edit_EnglishString
	#Edit_GermanString
	#Edit_IgnoreUnused
	#Edit_OK
	#Edit_Cancel
	#ReferenceViewer_Window
	#ReferenceViewer_List
	#ReferenceViewer_Close
EndEnumeration

#Title = "Language String Editor"

#Color_IgnoreUnused_Background = $00FFFF
#Color_IgnoreUnused_Text = $000000
#Color_NotTranslated_Background = $0000CC
#Color_NotTranslated_Text = $FFFFFF
#Color_Unused_Background = $000000
#Color_Unused_Text = $FFFFFF

Structure References
	fileName.s
	line.l
	content.s
EndStructure

Structure Strings
	englishString.s
	germanString.s
	ignoreUnused.b
	List references.References()
EndStructure

Global editStringID
Global fileChanged
Global serverRoot$
Global xmlFile$

Global Dim Strings.Strings(0)
Global NewList AssignStrings.Strings()

Procedure.s GetRegValue(hKey, path$, name$)
	dataCB = 255
	dataLP$ = Space(DataCB)
	If RegOpenKeyEx_(hKey, path$, 0, #KEY_ALL_ACCESS, @hKey) = #ERROR_SUCCESS
		If RegQueryValueEx_(hKey, name$, 0, @type, @dataLP$, @dataCB) = #ERROR_SUCCESS
			Select type
				Case #REG_SZ
					If RegQueryValueEx_(hKey, name$, 0, @type, @dataLP$, @dataCB) = #ERROR_SUCCESS
						ProcedureReturn Trim(Left(dataLP$, DataCB - 1))
					EndIf
				Case #REG_DWORD
					If RegQueryValueEx_(hKey, name$, 0, @type, @dataLP2, @dataCB) = #ERROR_SUCCESS
						ProcedureReturn Trim(Str(dataLP2))
					EndIf
			EndSelect
		EndIf
	EndIf
EndProcedure

Procedure IsEqual(value1, value2)
	If value1 = value2
		ProcedureReturn #True
	EndIf
EndProcedure

Procedure.s TrimEx(string$)
	newString$ = Trim(string$, Chr(13))
	newString$ = Trim(newString$, Chr(10))
	newString$ = Trim(newString$)
	If newString$ <> string$
		newString$ = TrimEx(newString$)
	EndIf
	ProcedureReturn newString$
EndProcedure

Procedure UpdateWindowSize(window)
	Select window
		Case #Edit_Window
			ResizeGadget(#Edit_ID, #PB_Ignore, #PB_Ignore, WindowWidth(#Edit_Window) - 100, #PB_Ignore)
			ResizeGadget(#Edit_EnglishString, #PB_Ignore, #PB_Ignore, WindowWidth(#Edit_Window) - 100, #PB_Ignore)
			ResizeGadget(#Edit_GermanString, #PB_Ignore, #PB_Ignore, WindowWidth(#Edit_Window) - 100, #PB_Ignore)
			ResizeGadget(#Edit_OK, WindowWidth(#Edit_Window) - 220, #PB_Ignore, #PB_Ignore, #PB_Ignore)
			ResizeGadget(#Edit_Cancel, WindowWidth(#Edit_Window) - 110, #PB_Ignore, #PB_Ignore, #PB_Ignore)
		Case #ReferenceViewer_Window
			ResizeGadget(#ReferenceViewer_List, #PB_Ignore, #PB_Ignore, WindowWidth(#ReferenceViewer_Window), WindowHeight(#ReferenceViewer_Window))
		Case #Window
			ResizeGadget(#Splitter, #PB_Ignore, #PB_Ignore, WindowWidth(#Window), WindowHeight(#Window) - MenuHeight())
	EndSelect
EndProcedure

Procedure WriteLog(string$)
	AddGadgetItem(#InfoList, -1, string$)
EndProcedure

Procedure SetFileChangedState(state)
	fileChanged = state
	If fileChanged
		SetWindowTitle(#Window, #Title + " [Changed]")
	Else
		SetWindowTitle(#Window, #Title)
	EndIf
EndProcedure

Procedure FindEmptySlot()
	For index = 0 To ArraySize(Strings())
		If Strings(index)\englishString = ""
			ProcedureReturn index
		EndIf
	Next
	ProcedureReturn ArraySize(Strings())
EndProcedure

Procedure TrimList()
	For stringID = 0 To ArraySize(Strings())
		If Strings(stringID)\englishString
			nonEmptyStringID = stringID
		EndIf
	Next
	ReDim Strings(nonEmptyStringID)
EndProcedure

Procedure ReloadList()
	ClearGadgetItems(#List)
	For item = 0 To ArraySize(Strings())
		showEntry = #False
		If Strings(item)\ignoreUnused
			backgroundColor = #Color_IgnoreUnused_Background
			textColor = #Color_IgnoreUnused_Text
			If GetMenuItemState(#Menu, #Menu_Show_IgnoreUnused)
				showEntry = #True
			EndIf
		ElseIf Strings(item)\englishString = ""
			backgroundColor = #Color_Unused_Background
			textColor = #Color_Unused_Text
			If GetMenuItemState(#Menu, #Menu_Show_Unused)
				showEntry = #True
			EndIf
		ElseIf Strings(item)\germanString = ""
			backgroundColor = #Color_NotTranslated_Background
			textColor = #Color_NotTranslated_Text
			If GetMenuItemState(#Menu, #Menu_Show_NotTranslated)
				showEntry = #True
			EndIf
		Else
			backgroundColor = -1
			textColor = -1
			If GetMenuItemState(#Menu, #Menu_Show_OK)
				showEntry = #True
			EndIf
		EndIf
		If showEntry
			AddGadgetItem(#List, -1, Str(item) + Chr(10) + Strings(item)\englishString + Chr(10) + Strings(item)\germanString + Chr(10) + Str(ListSize(Strings(item)\references())))
			listItem = CountGadgetItems(#List) - 1
			SetGadgetItemColor(#List, listItem, #PB_Gadget_BackColor, backgroundColor, -1)
			SetGadgetItemColor(#List, listItem, #PB_Gadget_FrontColor, textColor, -1)
		EndIf
	Next
EndProcedure

Procedure ShowReferences(stringID)
	If OpenWindow(#ReferenceViewer_Window, 100, 100, 800, 300, "Show references", #PB_Window_MinimizeGadget | #PB_Window_MaximizeGadget | #PB_Window_SizeGadget | #PB_Window_WindowCentered, WindowID(#Window))
		ListIconGadget(#ReferenceViewer_List, 0, 0, 0, 0, "Filename", 300, #PB_ListIcon_FullRowSelect)
		AddGadgetColumn(#ReferenceViewer_List, 1, "Line", 50)
		AddGadgetColumn(#ReferenceViewer_List, 2, "Content", 400)
		DisableWindow(#Window, #True)
		UpdateWindowSize(#ReferenceViewer_Window)
		AddKeyboardShortcut(#ReferenceViewer_Window, #PB_Shortcut_Escape, #ReferenceViewer_Close)
		ForEach Strings(stringID)\references()
			AddGadgetItem(#ReferenceViewer_List, -1, Strings(stringID)\references()\fileName + Chr(10) + Str(Strings(stringID)\references()\line) + Chr(10) + Strings(stringID)\references()\content)
		Next
	EndIf
EndProcedure

Procedure EditItem(stringID)
	If stringID = -1
		title$ = "Add language string"
		stringID = FindEmptySlot()
		englishString$ = ""
		germanString$ = ""
		ignoreUnused = #False
	Else
		title$ = "Edit language string"
		englishString$ = Strings(stringID)\englishString
		germanString$ = Strings(stringID)\germanString
		ignoreUnused = Strings(stringID)\ignoreUnused
	EndIf
	editStringID = stringID
	If OpenWindow(#Edit_Window, 100, 100, 500, 140, title$, #PB_Window_MinimizeGadget | #PB_Window_MaximizeGadget | #PB_Window_SizeGadget | #PB_Window_WindowCentered, WindowID(#Window))
		TextGadget(#Edit_Text1, 10, 10, 70, 20, "ID:")
		TextGadget(#Edit_Text2, 10, 40, 70, 20, "English:")
		TextGadget(#Edit_Text3, 10, 70, 70, 20, "English:")
		StringGadget(#Edit_ID, 90, 10, 0, 20, Str(stringID), #PB_String_Numeric)
		StringGadget(#Edit_EnglishString, 90, 40, 0, 20, englishString$)
		StringGadget(#Edit_GermanString, 90, 70, 0, 20, germanString$)
		CheckBoxGadget(#Edit_IgnoreUnused, 90, 100, 100, 20, "Ignore unused")
		ButtonGadget(#Edit_OK, 0, 100, 100, 30, "OK")
		ButtonGadget(#Edit_Cancel, 0, 100, 100, 30, "Cancel")
		DisableWindow(#Window, #True)
		WindowBounds(#Edit_Window, 230, WindowHeight(#Edit_Window), #PB_Ignore, WindowHeight(#Edit_Window))
		UpdateWindowSize(#Edit_Window)
		AddKeyboardShortcut(#Edit_Window, #PB_Shortcut_Return, #Edit_OK)
		AddKeyboardShortcut(#Edit_Window, #PB_Shortcut_Escape, #Edit_Cancel)
		SetGadgetState(#Edit_IgnoreUnused, ignoreUnused)
	EndIf
EndProcedure

Procedure CloseEditWindow()
	DisableWindow(#Window, #False)
	CloseWindow(#Edit_Window)
EndProcedure

Procedure EditOK()
	stringID = Val(GetGadgetText(#Edit_ID))
	englishString$ = Trim(GetGadgetText(#Edit_EnglishString))
	germanString$ = Trim(GetGadgetText(#Edit_GermanString))
	ignoreUnused = GetGadgetState(#Edit_IgnoreUnused)
	If stringID < 0
		MessageRequester("Invalid string ID", Str(stringID) + " is not a valid string ID!" + Chr(13) + Chr(13) + "Only use non-negative numbers!", #MB_ICONERROR)
		ProcedureReturn #False
	EndIf
	If englishString$ = ""
		MessageRequester("Empty English string", "An English string is required!", #MB_ICONERROR)
		ProcedureReturn #False
	EndIf
	If stringID <= ArraySize(Strings())
		If editStringID <> stringID And Strings(stringID)\englishString
			MessageRequester("Duplicate string ID", "The string ID " + Str(stringID) + " already exists in the list!", #MB_ICONERROR)
			ProcedureReturn #False
		EndIf
	EndIf
	For index = 0 To ArraySize(Strings())
		If editStringID <> index And Strings(index)\englishString = englishString$
			MessageRequester("Duplicate string", "The string '" + englishString$ + "' already exists in the list!", #MB_ICONERROR)
			ProcedureReturn #False
		EndIf
	Next
	If stringID >= ArraySize(Strings())
		ReDim Strings(stringID)
	EndIf
	Strings(editStringID)\englishString = ""
	Strings(editStringID)\germanString = ""
	Strings(editStringID)\ignoreUnused = #False
	Strings(stringID)\englishString = englishString$
	Strings(stringID)\germanString = germanString$
	Strings(stringID)\ignoreUnused = ignoreUnused
	ReloadList()
	CloseEditWindow()
	For item = 0 To CountGadgetItems(#List) - 1
		If Val(GetGadgetItemText(#List, item, 0)) = stringID
			SetGadgetState(#List, item)
			Break
		EndIf
	Next
	SetFileChangedState(#True)
	ProcedureReturn #True
EndProcedure

Procedure AddString(stringID, englishString$, germanString$, addNotExisting, ignoreUnused, referenceFileName$, referenceLine, referenceContent$)
	alreadyExisting = #False
	For index = 0 To ArraySize(Strings())
		If Strings(index)\englishString = englishString$
			Strings(index)\ignoreUnused = ignoreUnused
			If germanString$
				Strings(index)\germanString = germanString$
			EndIf
			If referenceFileName$
				AddElement(Strings(index)\references())
				Strings(index)\references()\fileName = referenceFileName$
				Strings(index)\references()\line = referenceLine
				Strings(index)\references()\content = referenceContent$
			EndIf
			alreadyExisting = #True
			Break
		EndIf
	Next
	If Not alreadyExisting
		If addNotExisting
			If stringID = -1
				AddElement(AssignStrings())
				AssignStrings()\englishString = englishString$
				AssignStrings()\germanString = germanString$
				AssignStrings()\ignoreUnused = ignoreUnused
				If referenceFileName$
					AddElement(AssignStrings()\references())
					AssignStrings()\references()\fileName = referenceFileName$
					AssignStrings()\references()\line = referenceLine
					AssignStrings()\references()\content = referenceContent$
				EndIf
			Else
				If stringID > ArraySize(Strings())
					ReDim Strings(stringID)
				EndIf
				Strings(stringID)\englishString = englishString$
				Strings(stringID)\germanString = germanString$
				Strings(stringID)\ignoreUnused = ignoreUnused
				If referenceFileName$
					AddElement(Strings(stringID)\references())
					Strings(stringID)\references()\fileName = referenceFileName$
					Strings(stringID)\references()\line = referenceLine
					Strings(stringID)\references()\content = referenceContent$
				EndIf
			EndIf
		Else
			WriteLog("String ID " + Str(stringID) + " is not used anymore: " + englishString$)
		EndIf
	EndIf
EndProcedure

Procedure SaveStringsInFile(fileName$)
	stringIDRegEx = CreateRegularExpression(#PB_Any, "StringID:([0-9\-]+)\(" + Chr(34) + "(.*?)" + Chr(34) + "\)")
	idRegEx = CreateRegularExpression(#PB_Any, "StringID:([0-9\-]+)")
	stringRegEx = CreateRegularExpression(#PB_Any, Chr(34) + "(.*?)" + Chr(34))
	inputFile = ReadFile(#PB_Any, fileName$)
	If IsFile(inputFile)
		outputFile = CreateFile(#PB_Any, fileName$ + ".tmp")
		If IsFile(outputFile)
			Repeat
				lineIndex + 1
				line$ = ReadString(inputFile)
				Dim matches$(0)
				count = ExtractRegularExpression(stringIDRegEx, line$, matches$())
				For match = 0 To count - 1
					Dim ids$(0)
					ExtractRegularExpression(idRegEx, matches$(match), ids$())
					stringID = Val(RemoveString(ids$(0), "StringID:"))
					Dim strings$(0)
					ExtractRegularExpression(stringRegEx, matches$(match), strings$())
					string$ = Trim(strings$(0), Chr(34))
					If string$
						newStringID = -1
						For index = 0 To ArraySize(Strings())
							If Strings(index)\englishString = string$
								newStringID = index
								Break
							EndIf
						Next
						If newStringID <> -1 And newStringID <> stringID
							WriteLog("Updating " + fileName$ + ":" + Str(lineIndex))
							line$ = ReplaceString(line$, matches$(match), "StringID:" + Str(newStringID) + "(" + Chr(34) + string$ + Chr(34) + ")")
							updateRequired = #True
						EndIf
					Else
						WriteLog("Warning: Missing text for string ID " + Str(stringID) + " in " +fileName$ + ":" + Str(lineIndex))
					EndIf
				Next
				If lineIndex > 1
					WriteString(outputFile, Chr(10))
				EndIf
				WriteString(outputFile, line$)
			Until Eof(inputFile)
			CloseFile(outputFile)
			result = #True
		Else
			WriteLog("Error: Unable to create file: " + fileName$ + ".tmp")
		EndIf
		CloseFile(inputFile)
		If result
			If updateRequired
				result = #False
				If DeleteFile(fileName$) And RenameFile(fileName$ + ".tmp", fileName$)
					result = #True
				EndIf
			Else
				DeleteFile(fileName$ + ".tmp")
			EndIf
		EndIf
	Else
		WriteLog("Error: Unable to read file: " + fileName$)
	EndIf
	ProcedureReturn result
EndProcedure

Procedure SaveStringsInDirectory(path$)
	dir = ExamineDirectory(#PB_Any, path$, "*.*")
	If IsDirectory(dir)
		result = #True
		While NextDirectoryEntry(dir)
			name$ = DirectoryEntryName(dir)
			If name$ <> "." And name$ <> ".."
				Select DirectoryEntryType(dir)
					Case #PB_DirectoryEntry_File
						If GetExtensionPart(name$) = "inc"
							If Not SaveStringsInFile(path$ + "\" + name$)
								result = #False
							EndIf
						EndIf
					Case #PB_DirectoryEntry_Directory
						If Not SaveStringsInDirectory(path$ + "\" + name$)
							result = #False
						EndIf
				EndSelect
			EndIf
		Wend
		FinishDirectory(dir)
		ProcedureReturn result
	EndIf
EndProcedure

Procedure ScanStringsInFile(fileName$)
	stringIDRegEx = CreateRegularExpression(#PB_Any, "StringID:([0-9\-]+)\(" + Chr(34) + "(.*?)" + Chr(34) + "\)")
	idRegEx = CreateRegularExpression(#PB_Any, "StringID:([0-9\-]+)")
	stringRegEx = CreateRegularExpression(#PB_Any, Chr(34) + "(.*?)" + Chr(34))
	file = ReadFile(#PB_Any, fileName$)
	If IsFile(file)
		Repeat
			lineIndex + 1
			line$ = ReadString(file)
			Dim matches$(0)
			count = ExtractRegularExpression(stringIDRegEx, line$, matches$())
			For match = 0 To count - 1
				Dim ids$(0)
				ExtractRegularExpression(idRegEx, matches$(match), ids$())
				stringID = Val(RemoveString(ids$(0), "StringID:"))
				Dim strings$(0)
				ExtractRegularExpression(stringRegEx, matches$(match), strings$())
				string$ = Trim(strings$(0), Chr(34))
				If string$
					AddString(stringID, string$, "", #True, #False, fileName$, lineIndex, line$)
				Else
					WriteLog("Warning: Missing text for string ID " + Str(stringID) + " in " +fileName$ + ":" + Str(lineIndex))
				EndIf
			Next
		Until Eof(file)
		CloseFile(file)
	Else
		WriteLog("Error: Unable to read file: " + fileName$)
	EndIf
EndProcedure

Procedure ScanStringsInDirectory(path$)
	dir = ExamineDirectory(#PB_Any, path$, "*.*")
	If IsDirectory(dir)
		While NextDirectoryEntry(dir)
			name$ = DirectoryEntryName(dir)
			If name$ <> "." And name$ <> ".."
				Select DirectoryEntryType(dir)
					Case #PB_DirectoryEntry_File
						If GetExtensionPart(name$) = "inc"
							ScanStringsInFile(path$ + "\" + name$)
						EndIf
					Case #PB_DirectoryEntry_Directory
						ScanStringsInDirectory(path$ + "\" + name$)
				EndSelect
			EndIf
		Wend
		FinishDirectory(dir)
	EndIf
EndProcedure

Procedure LoadLanguageStrings()
	Dim Strings(0)
	ScanStringsInDirectory(serverRoot$ + "includes\grgserver")
	If LoadXML(#XML, xmlFile$)
		If XMLStatus(#XML) = #PB_XML_Success
			*mainNode = MainXMLNode(#XML)
			If *mainNode
				*stringNode = XMLNodeFromPath(*mainNode, "string")
				While *stringNode
					stringID = Val(GetXMLAttribute(*stringNode, "id"))
					ignoreUnused = Val(GetXMLAttribute(*stringNode, "ignoreUnused"))
					englishString$ = ""
					*languageNode = XMLNodeFromPath(*stringNode, "en")
					If *languageNode
						englishString$ = TrimEx(GetXMLNodeText(*languageNode))
					EndIf
					germanString$ = ""
					*languageNode = XMLNodeFromPath(*stringNode, "de")
					If *languageNode
						germanString$ = TrimEx(GetXMLNodeText(*languageNode))
					EndIf
					AddString(stringID, englishString$, germanString$, ignoreUnused, ignoreUnused, "", 0, "")
					*stringNode = NextXMLNode(*stringNode)
				Wend
				SetFileChangedState(#False)
			Else
				MessageRequester("No main node", "No main node found in XML file!", #MB_ICONERROR)
			EndIf
		Else
			message$ = "Error in XML file!" + Chr(13)
			message$ + Chr(13)
			message$ + "Code: " + Str(XMLStatus(#XML)) + Chr(13)
			message$ + "Line: " + Str(XMLErrorLine(#XML)) + Chr(13)
			message$ + "Character: " + Str(XMLErrorPosition(#XML)) + Chr(13)
			message$ + Chr(13)
			message$ + XMLError(#XML)
			MessageRequester("XML error", message$, #MB_ICONERROR)
		EndIf
		FreeXML(#XML)
	EndIf
	ForEach AssignStrings()
		stringID = FindEmptySlot()
		If StringID >= ArraySize(Strings())
			ReDim Strings(stringID)
		EndIf
		Strings(stringID)\englishString = AssignStrings()\englishString
		Strings(stringID)\germanString = AssignStrings()\germanString
		Strings(stringID)\ignoreUnused= AssignStrings()\ignoreUnused
		CopyList(AssignStrings()\references(), Strings(stringID)\references())
	Next
	ClearList(AssignStrings())
	ReloadList()
EndProcedure

Procedure UpdateConfig()
	regEx = CreateRegularExpression(#PB_Any, "LanguageStringLimit\(([0-9]+)\)")
	fileName$ = serverRoot$ + "includes\grgserver\config.inc"
	inputFile = ReadFile(#PB_Any, fileName$)
	If IsFile(inputFile)
		outputFile = CreateFile(#PB_Any, fileName$ + ".tmp")
		If IsFile(outputFile)
			Repeat
				lineIndex + 1
				line$ = ReadString(inputFile)
				Dim matches$(0)
				If ExtractRegularExpression(regEx, line$, matches$())
					oldLimit = Val(RemoveString(RemoveString(matches$(0), "LanguageStringLimit("), ")"))
					newLimit = ArraySize(Strings()) + 1
					If oldLimit <> newLimit
						WriteLog("Updating language string limit (" + Str(oldLimit) + " -> " + Str(newLimit) + ")")
						line$ = ReplaceString(line$, matches$(0), "LanguageStringLimit(" + Str(newLimit) + ")")
						updateRequired = #True
					EndIf
				EndIf
				If lineIndex > 1
					WriteString(outputFile, Chr(10))
				EndIf
				WriteString(outputFile, line$)
			Until Eof(inputFile)
			CloseFile(outputFile)
			result = #True
		Else
			WriteLog("Error: Unable to create file: " + fileName$ + ".tmp")
		EndIf
		CloseFile(inputFile)
		If result
			If updateRequired
				result = #False
				If DeleteFile(fileName$) And RenameFile(fileName$ + ".tmp", fileName$)
					result = #True
				EndIf
			Else
				DeleteFile(fileName$ + ".tmp")
			EndIf
		EndIf
	Else
		WriteLog("Error: Unable to read file: " + fileName$)
	EndIf
	ProcedureReturn result
EndProcedure

Procedure Save()
	xml = CreateXML(#PB_Any, #PB_Ascii)
	If IsXML(xml)
		*mainNode = CreateXMLNode(RootXMLNode(xml))
		SetXMLNodeName(*mainNode, "languagestrings")
		For stringID = 0 To ArraySize(Strings())
			If Strings(stringID)\englishString
				*stringNode = CreateXMLNode(*mainNode)
				SetXMLNodeName(*stringNode, "string")
				SetXMLAttribute(*stringNode, "id", Str(stringID))
				If Strings(stringID)\ignoreUnused
					SetXMLAttribute(*stringNode, "ignoreUnused", "1")
				EndIf
				*englishNode = CreateXMLNode(*stringNode)
				SetXMLNodeName(*englishNode, "en")
				SetXMLNodeText(*englishNode, Strings(stringID)\englishString)
				*germanNode = CreateXMLNode(*stringNode)
				SetXMLNodeName(*germanNode, "de")
				SetXMLNodeText(*germanNode, Strings(stringID)\germanString)
			EndIf
		Next
		FormatXML(xml, #PB_XML_LinuxNewline | #PB_XML_ReIndent | #PB_XML_ReFormat, 4)
		If SaveXML(xml, xmlFile$)
			If SaveStringsInDirectory(serverRoot$ + "includes\grgserver")
				If UpdateConfig()
					SetFileChangedState(#False)
					ProcedureReturn #True
				EndIf
			EndIf
		EndIf
	EndIf
EndProcedure

Procedure CheckQuit()
	If fileChanged
		Select MessageRequester("Unsaved changes", "There are unsaved changes!" + Chr(13) + Chr(13) + "Do you want to save before quit?", #MB_YESNOCANCEL | #MB_ICONQUESTION)
			Case #PB_MessageRequester_Yes
				If Save()
					End
				Else
					MessageRequester("Save", "Saving failed!" + Chr(13) + Chr(13) + "Click OK to go back without exiting the application.", #MB_ICONERROR)
				EndIf
			Case #PB_MessageRequester_No
				End
		EndSelect
	Else
		End
	EndIf
EndProcedure

Procedure SearchString(string$)
	startingID = Val(GetGadgetItemText(#List, GetGadgetState(#List) + 1, 0))
	If startingID > ArraySize(Strings())
		startingID = 0
	EndIf
	For stringID = startingID To ArraySize(Strings())
		If FindString(Strings(stringID)\englishString, string$, 1, #PB_String_NoCase) Or FindString(Strings(stringID)\germanString, string$, 1, #PB_String_NoCase)
			For item = 0 To CountGadgetItems(#List) - 1
				If Val(GetGadgetItemText(#List, item, 0)) = stringID
					SetGadgetState(#List, item)
					ProcedureReturn #True
				EndIf
			Next
		EndIf
	Next
	MessageRequester("Search string", "The entered string '" + string$ + "' was not found!", #MB_ICONERROR)
EndProcedure

Procedure SearchStringID(stringID)
	For item = 0 To CountGadgetItems(#List) - 1
		If Val(GetGadgetItemText(#List, item, 0)) = stringID
			SetGadgetState(#List, item)
			ProcedureReturn #True
		EndIf
	Next
	MessageRequester("Search string", "The string ID " + Str(stringID) + " was not found!", #MB_ICONERROR)
EndProcedure

nppExecutable$ = Trim(GetRegValue(#HKEY_LOCAL_MACHINE, "SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\notepad++.exe", ""), Chr(34))

serverRoot$ = ProgramParameter()
If serverRoot$ = ""
	mainPath$ = GetPathPart(ProgramFilename())
	serverRoot$ = GetPathPart(Left(mainPath$, Len(mainPath$) - 1))
EndIf

xmlFile$ = serverRoot$ + "scriptfiles\languagestrings.xml"

If OpenWindow(#Window, 100, 100, 800, 500, #Title, #PB_Window_MinimizeGadget | #PB_Window_MaximizeGadget | #PB_Window_SizeGadget | #PB_Window_ScreenCentered)
	If CreateMenu(#Menu, WindowID(#Window))
		MenuTitle("File")
		MenuItem(#Menu_Reload, "Reload")
		MenuItem(#Menu_Save, "Save" + Chr(9) + "Ctrl+S")
		MenuBar()
		MenuItem(#Menu_Quit, "Quit" + Chr(9) + "Alt+F4")
		MenuTitle("Edit")
		MenuItem(#Menu_Add, "Add" + Chr(9) + "Ins")
		MenuItem(#Menu_Edit, "Edit")
		MenuBar()
		MenuItem(#Menu_Delete, "Delete" + Chr(9) + "Del")
		MenuBar()
		MenuItem(#Menu_Goto, "Goto ID" + Chr(9) + "Ctrl+G")
		MenuItem(#Menu_Search, "Search" + Chr(9) + "Ctrl+F")
		MenuItem(#Menu_SearchNext, "Search next" + Chr(9) + "F3")
		MenuBar()
		MenuItem(#Menu_ShowReferences, "Show references" + Chr(9) + "Ctrl+R")
		MenuTitle("View")
		OpenSubMenu("Show")
		MenuItem(#Menu_Show_IgnoreUnused, "Show ignore unused")
		MenuItem(#Menu_Show_NotTranslated, "Show not translated")
		MenuItem(#Menu_Show_OK, "Show OK")
		MenuItem(#Menu_Show_Unused, "Show unused")
		CloseSubMenu()
		DisableMenuItem(#Menu, #Menu_Edit, #True)
		DisableMenuItem(#Menu, #Menu_Delete, #True)
		DisableMenuItem(#Menu, #Menu_ShowReferences, #True)
		SetMenuItemState(#Menu, #Menu_Show_IgnoreUnused, #True)
		SetMenuItemState(#Menu, #Menu_Show_NotTranslated, #True)
		SetMenuItemState(#Menu, #Menu_Show_OK, #True)
		SetMenuItemState(#Menu, #Menu_Show_Unused, #True)
	EndIf
	ListIconGadget(#List, 0, 0, 0, 0, "ID", 50, #PB_ListIcon_FullRowSelect)
	AddGadgetColumn(#List, 1, "English", 300)
	AddGadgetColumn(#List, 2, "German", 300)
	AddGadgetColumn(#List, 3, "References", 100)
	ListViewGadget(#InfoList, 0, 0, 0, 0)
	SplitterGadget(#Splitter, 0, 0, 0, 0, #List, #InfoList, #PB_Splitter_Separator)
	UpdateWindowSize(#Window)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Control | #PB_Shortcut_S, #Menu_Save)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Insert, #Menu_Add)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Delete, #Menu_Delete)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Control | #PB_Shortcut_G, #Menu_Goto)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Control | #PB_Shortcut_F, #Menu_Search)
	AddKeyboardShortcut(#Window, #PB_Shortcut_F3, #Menu_SearchNext)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Control | #PB_Shortcut_R, #Menu_ShowReferences)
	SetGadgetState(#Splitter, 400)
	LoadLanguageStrings()
	Repeat
		Select WaitWindowEvent()
			Case #PB_Event_Gadget
				Select EventGadget()
					Case #List
						item = GetGadgetState(#List)
						DisableMenuItem(#Menu, #Menu_Edit, IsEqual(item, -1))
						DisableMenuItem(#Menu, #Menu_Delete, IsEqual(item, -1))
						DisableMenuItem(#Menu, #Menu_ShowReferences, IsEqual(item, -1))
						Select EventType()
							Case #PB_EventType_LeftDoubleClick
								If item = -1
									stringID = -1
								Else
									stringID = Val(GetGadgetItemText(#List, item, 0))
								EndIf
								EditItem(stringID)
							Case #PB_EventType_RightClick
								If CreatePopupMenu(#PopupMenu)
									MenuItem(#Menu_Add, "Add" + Chr(9) + "Ins")
									If item <> -1
										MenuItem(#Menu_Edit, "Edit")
										MenuBar()
										MenuItem(#Menu_ShowReferences, "Show references")
										MenuBar()
										MenuItem(#Menu_Delete, "Delete" + Chr(9) + "Del")
									EndIf
									DisplayPopupMenu(#PopupMenu, WindowID(#Window))
								EndIf
						EndSelect
					Case #Edit_OK
						EditOK()
					Case #Edit_Cancel
						CloseEditWindow()
					Case #ReferenceViewer_List
						Select EventType()
							Case #PB_EventType_LeftDoubleClick
								item = GetGadgetState(#ReferenceViewer_List)
								If item <> -1
									RunProgram(nppExecutable$, "-n" + GetGadgetItemText(#ReferenceViewer_List, item, 1) + " " +Chr(34) + GetGadgetItemText(#ReferenceViewer_List, item, 0) + Chr(34), GetPathPart(nppExecutable$))
								EndIf
						EndSelect
				EndSelect
			Case #PB_Event_Menu
				item = GetGadgetState(#List)
				Select EventMenu()
					Case #Menu_Reload
						If fileChanged
							If MessageRequester("Reload file", "Are you sure to reload all language strings from the XML file?" + Chr(13) + Chr(13) + "You will lose all unsaved changes!", #MB_YESNO | #MB_ICONQUESTION) = #PB_MessageRequester_Yes
								LoadLanguageStrings()
							EndIf
						Else
							LoadLanguageStrings()
						EndIf
					Case #Menu_Save
						If Save()
							MessageRequester("Save", "Language strings saved", #MB_ICONINFORMATION)
						Else
							MessageRequester("Save", "Saving failed!", #MB_ICONERROR)
						EndIf
					Case #Menu_Quit
						CheckQuit()
					Case #Menu_Add
						EditItem(-1)
					Case #Menu_Edit
						If item <> -1
							EditItem(Val(GetGadgetItemText(#List, item, 0)))
						EndIf
					Case #Menu_Delete
						If item <> -1
							If MessageRequester("Delete language string", "Delete the selected language string?" + Chr(13) + Chr(13) + "ID: " + GetGadgetItemText(#List, item, 0), #MB_YESNO | #MB_ICONQUESTION) = #PB_MessageRequester_Yes
								stringID = Val(GetGadgetItemText(#List, item, 0))
								Strings(stringID)\englishString = ""
								Strings(stringID)\germanString = ""
								Strings(stringID)\ignoreUnused = #False
								TrimList()
								ReloadList()
								SetFileChangedState(#True)
							EndIf
						EndIf
					Case #Menu_Goto
						string$ = Trim(InputRequester("Goto string ID", "Enter the string ID you want to go to.", ""))
						If string$
							stringID = Val(string$)
							If Str(stringID) = string$
								SearchStringID(stringID)
							Else
								MessageRequester("Not a number", "The entered text is not a number!", #MB_ICONERROR)
							EndIf
						EndIf
					Case #Menu_Search
						string$ = Trim(InputRequester("Search string", "Enter the string you want to search for.", searchedString$))
						If string$
							searchedString$ = string$
							SearchString(string$)
						EndIf
					Case #Menu_SearchNext
						If searchedString$
							SearchString(searchedString$)
						Else
							string$ = Trim(InputRequester("Search string", "Enter the string you want to search for.", searchedString$))
							If string$
								searchedString$ = string$
								SearchString(string$)
							EndIf
						EndIf
					Case #Menu_ShowReferences
						item = GetGadgetState(#List)
						If item <> -1
							ShowReferences(Val(GetGadgetItemText(#List, item, 0)))
						EndIf
					Case #Menu_Show_IgnoreUnused
						SetMenuItemState(#Menu, #Menu_Show_IgnoreUnused, IsEqual(GetMenuItemState(#Menu, #Menu_Show_IgnoreUnused), #False))
						ReloadList()
					Case #Menu_Show_NotTranslated
						SetMenuItemState(#Menu, #Menu_Show_NotTranslated, IsEqual(GetMenuItemState(#Menu, #Menu_Show_NotTranslated), #False))
						ReloadList()
					Case #Menu_Show_OK
						SetMenuItemState(#Menu, #Menu_Show_OK, IsEqual(GetMenuItemState(#Menu, #Menu_Show_OK), #False))
						ReloadList()
					Case #Menu_Show_Unused
						SetMenuItemState(#Menu, #Menu_Show_Unused, IsEqual(GetMenuItemState(#Menu, #Menu_Show_Unused), #False))
						ReloadList()
					Case #Edit_OK
						EditOK()
					Case #Edit_Cancel
						CloseEditWindow()
					Case #ReferenceViewer_Close
						DisableWindow(#Window, #False)
						CloseWindow(#ReferenceViewer_Window)
				EndSelect
			Case #PB_Event_SizeWindow
				UpdateWindowSize(EventWindow())
			Case #PB_Event_CloseWindow
				Select EventWindow()
					Case #Window
						CheckQuit()
					Case #Edit_Window
						CloseEditWindow()
					Case #ReferenceViewer_Window
						DisableWindow(#Window, #False)
						CloseWindow(#ReferenceViewer_Window)
				EndSelect
		EndSelect
	ForEver
EndIf
; IDE Options = PureBasic 5.11 (Windows - x86)
; CursorPosition = 633
; FirstLine = 627
; Folding = -----
; EnableXP
; UseIcon = Language String Editor.ico
; Executable = Language String Editor.exe
; CommandLine = X:\Projects\SAMP-Server\
; EnableCompileCount = 357
; EnableBuildCount = 18
; EnableExeConstant
; IncludeVersionInfo
; VersionField0 = 1,0,0,0
; VersionField1 = 1,0,0,0
; VersionField2 = SelfCoders
; VersionField3 = Language String Editor
; VersionField4 = 1.0
; VersionField5 = 1.0
; VersionField6 = Language String Editor
; VersionField7 = Language String Editor
; VersionField8 = %EXECUTABLE
; VersionField13 = languagestringeditor@selfcoders.com
; VersionField14 = http://www.selfcoders.com
; VersionField15 = VOS_NT_WINDOWS32
; VersionField16 = VFT_APP
; VersionField17 = 0409 English (United States)
; VersionField18 = Build
; VersionField19 = Compile OS
; VersionField20 = Date
; VersionField21 = %BUILDCOUNT
; VersionField22 = %OS
; VersionField23 = %y-%m-%d %h:%i:%s