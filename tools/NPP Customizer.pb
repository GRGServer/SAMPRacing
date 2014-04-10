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

Procedure.s GetPath(pathID)
	path$ = Space(#MAX_PATH)
	If SHGetSpecialFolderLocation_(0, pathID, @pID) = #NOERROR
		SHGetPathFromIDList_(pID, @path$)
		path$ = Trim(path$)
		If Path$
			If Right(path$, 1) <> "\"
				path$ + "\"
			EndIf
			ProcedureReturn path$
		EndIf
		CoTaskMemFree_(pID)
	EndIf
EndProcedure

#Title = "Notepad++ Customizer"

AppData$ = GetPath(26)
NppPath$ = GetPathPart(RemoveString(GetRegValue(#HKEY_LOCAL_MACHINE, "SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\notepad++.exe", ""), Chr(34)))
NppAppData$ = AppData$ + "Notepad++\"
MainPath$ = GetPathPart(ProgramFilename())
ServerRoot$ = GetPathPart(Left(MainPath$, Len(MainPath$) - 1))

If MessageRequester(#Title, "Please verify the following paths:" + Chr(13) + Chr(13) + "SAMP-Server directory: " + Chr(13) + ServerRoot$ + Chr(13) + Chr(13) + "Notepad++ program directory: " + Chr(13) + NppPath$ + Chr(13) + Chr(13) + "Notepad++ user config directory: " + Chr(13) + NppAppData$ + Chr(13) + Chr(13) + "Is that correct?", #MB_YESNO | #MB_ICONQUESTION) = #PB_MessageRequester_Yes
	If MessageRequester(#Title, "Please make sure Notepad++ is not running!" + Chr(13) + Chr(13) + "Continue?", #MB_YESNO | #MB_ICONWARNING) = #PB_MessageRequester_Yes
		CreateDirectory(NppAppData$)
		CreateDirectory(NppAppData$ + "plugins")
		CreateDirectory(NppAppData$ + "plugins\config")
		CreateDirectory(NppPath$ + "plugins")
		CreateDirectory(NppPath$ + "plugins\APIs")
		File = CreateFile(#PB_Any, NppAppData$ + "plugins\config\npes_saved.txt")
		If IsFile(File)
			WriteStringN(File, "::Pawn Compile")
			WriteStringN(File, "NPP_SAVE")
			WriteStringN(File, "cd $(CURRENT_DIRECTORY)")
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\pawn\pawncc.exe" + Chr(34)+ " $(FILE_NAME) " + Chr(34) + "-i" + ServerRoot$ + "includes" + Chr(34) + " -; -(")
			WriteStringN(File, "::Compile GRG Server")
			WriteStringN(File, "NPP_SAVE")
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\compile-gamemode.bat" + Chr(34))
			WriteStringN(File, "::Todo Finder")
			WriteStringN(File, "NPP_SAVE")
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\todo-finder.bat" + Chr(34))
			CloseFile(File)
		EndIf
		CopyFile(MainPath$ + "npp\pawn.api", NppPath$ + "plugins\APIs\pawn.api")
		CopyFile(MainPath$ + "npp\PAWN.xml", NppPath$ + "plugins\APIs\PAWN.xml")
		CopyFile(MainPath$ + "npp\NppExec.dll", NppPath$ + "plugins\NppExec.dll")
		CopyFile(MainPath$ + "npp\insertExt.ini", NppAppData$ + "insertExt.ini")
		CopyFile(MainPath$ + "npp\NppExec.ini", NppAppData$ + "plugins\config\NppExec.ini")
		CopyFile(MainPath$ + "npp\langs.xml", NppAppData$ + "langs.xml")
		CopyFile(MainPath$ + "npp\userDefineLang.xml", NppAppData$ + "userDefineLang.xml")
		MessageRequester(#Title, "Done", #MB_ICONINFORMATION)
	EndIf
EndIf