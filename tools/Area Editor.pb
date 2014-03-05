Enumeration
	#MapImage
	#MergedImage
	#Window
	#ToolBar
	#Save
	#DeleteCurrentPoint
	#ScrollArea
	#MapCanvas
	#AreaSelection
	#NewArea
	#PointList
	#DeleteArea
	#NewArea_Window
	#NewArea_Text1
	#NewArea_Text2
	#NewArea_Name
	#NewArea_Type
	#NewArea_OK
EndEnumeration

#Title = "Area Editor"

Structure Area
	name.s
	type.s
	List points.Point()
EndStructure

Global scriptFilesPath$
Global fileChanged
Global NewList Areas.Area()

Procedure GetDistanceBetweenPoints(*point1.Point, *point2.Point)
	ProcedureReturn Sqr(Pow(*point1\x - *point2\x, 2)) + Sqr(Pow(*point1\y - *point2\y, 2))
EndProcedure

Procedure UpdateImage()
	If StartDrawing(CanvasOutput(#MapCanvas))
		DrawImage(ImageID(#MapImage), 0, 0)
		FrontColor(RGB(0, 0, 255))
		item = GetGadgetState(#AreaSelection)
		If item <> -1
			SelectElement(Areas(), item)
			pointListItem = GetGadgetState(#PointList)
			ClearGadgetItems(#PointList)
			lastPoint = ListSize(Areas()\points()) - 1
			For point = 0 To lastPoint
				SelectElement(Areas()\points(), point)
				AddGadgetItem(#PointList, -1, Str(Areas()\points()\x) + Chr(10) + Str(Areas()\points()\y))
				startX = Areas()\points()\x + 3000
				startY = Areas()\points()\y * -1 + 3000
				If lastPoint = 0
					Plot(startX, startY)
				Else
					If point = lastPoint
						SelectElement(Areas()\points(), 0)
					Else
						SelectElement(Areas()\points(), point + 1)
					EndIf
					endX = Areas()\points()\x + 3000
					endY = Areas()\points()\y * -1 + 3000
					LineXY(startX, startY, endX, endY)
				EndIf
				If point = pointListItem
					Circle(startX, startY, 5, RGB(255, 255, 0))
					scrollX = GetGadgetAttribute(#ScrollArea, #PB_ScrollArea_X)
					scrollY = GetGadgetAttribute(#ScrollArea, #PB_ScrollArea_Y)
					If startX < scrollX Or startX > scrollX + GadgetWidth(#ScrollArea)
						SetGadgetAttribute(#ScrollArea, #PB_ScrollArea_X, startX - GadgetWidth(#ScrollArea) / 2)
					EndIf
					If startY < scrollY Or startY > scrollY + GadgetHeight(#ScrollArea)
						SetGadgetAttribute(#ScrollArea, #PB_ScrollArea_Y, startY - GadgetHeight(#ScrollArea) / 2)
					EndIf
				EndIf
			Next
			SetGadgetState(#PointList, pointListItem)
		EndIf
		StopDrawing()
	EndIf
EndProcedure

Procedure UpdateAreaSelectBox()
	ClearGadgetItems(#AreaSelection)
	ForEach Areas()
		AddGadgetItem(#AreaSelection, -1, Areas()\name + " [" + Areas()\type + "]")
	Next
EndProcedure

Procedure LoadAreas()
	xml = LoadXML(#PB_Any, scriptFilesPath$ + "areas.xml")
	If IsXML(xml)
		If XMLStatus(xml) = #PB_XML_Success
			*mainNode = MainXMLNode(xml)
			If *mainNode
				*areaNode = XMLNodeFromPath(*mainNode, "area")
				While *areaNode
					AddElement(Areas())
					Areas()\name = GetXMLAttribute(*areaNode, "name")
					Areas()\type = GetXMLAttribute(*areaNode, "type")
					*pointNode = XMLNodeFromPath(*areaNode, "point")
					While *pointNode
						AddElement(Areas()\points())
						Areas()\points()\x = Val(GetXMLAttribute(*pointNode, "x"))
						Areas()\points()\y = Val(GetXMLAttribute(*pointNode, "y"))
						*pointNode = NextXMLNode(*pointNode)
					Wend
					*areaNode = NextXMLNode(*areaNode)
				Wend
				fileChanged = #False
				UpdateAreaSelectBox()
			Else
				MessageRequester(#Title, "No main node found in XML file!", #MB_ICONERROR)
			EndIf
		Else
			MessageRequester(#Title, "Can not load XML file!" + Chr(13) + Chr(13) + "Message: " + XMLError(xml) + Chr(13) + "Line: " + Str(XMLErrorLine(xml)) + Chr(13) + "Character: " + Str(XMLErrorPosition(xml)), #MB_ICONERROR)
		EndIf
	EndIf
EndProcedure

Procedure SaveAreas()
	xml = CreateXML(#PB_Any, #PB_Ascii)
	If IsXML(xml)
		*mainNode = CreateXMLNode(RootXMLNode(xml))
		SetXMLNodeName(*mainNode, "areas")
		ForEach Areas()
			*areaNode = CreateXMLNode(*mainNode)
			SetXMLNodeName(*areaNode, "area")
			SetXMLAttribute(*areaNode, "name", Areas()\name)
			SetXMLAttribute(*areaNode, "type", Areas()\type)
			ForEach Areas()\points()
				*pointNode = CreateXMLNode(*areaNode)
				SetXMLNodeName(*pointNode, "point")
				SetXMLAttribute(*pointNode, "x", Str(Areas()\points()\x))
				SetXMLAttribute(*pointNode, "y", Str(Areas()\points()\y))
			Next
		Next
		FormatXML(xml, #PB_XML_LinuxNewline | #PB_XML_ReIndent | #PB_XML_ReFormat, 4)
		saveOK = SaveXML(xml, scriptFilesPath$ + "areas.xml")
		FreeXML(xml)
		If saveOK
			fileChanged = #False
			ProcedureReturn #True
		EndIf
	EndIf
EndProcedure

CompilerIf #PB_Compiler_Debugger
	toolsPath$ = GetCurrentDirectory()
CompilerElse
	toolsPath$ = GetPathPart(ProgramFilename())
CompilerEndIf

rootPath$ = GetPathPart(Left(toolsPath$, Len(toolsPath$) - 1))
scriptFilesPath$ = rootPath$ + "scriptfiles\"

UseJPEGImageDecoder()

If Not LoadImage(#MapImage, toolsPath$ + "map.jpg")
	MessageRequester(#Title, "Can not load image 'map.jpg'!", #MB_ICONERROR)
	End
EndIf

If OpenWindow(#Window, 100, 100, 800, 600, #Title, #PB_Window_MinimizeGadget | #PB_Window_MaximizeGadget | #PB_Window_SizeGadget | #PB_Window_ScreenCentered)
	If CreateToolBar(#ToolBar, WindowID(#Window))
		ToolBarStandardButton(#Save, #PB_ToolBarIcon_Save)
	EndIf

	ScrollAreaGadget(#ScrollArea, 0, ToolBarHeight(#ToolBar), 0, 0, ImageWidth(#MapImage), ImageHeight(#MapImage), 100, #PB_ScrollArea_Center)
	CanvasGadget(#MapCanvas, 0, 0, ImageWidth(#MapImage), ImageHeight(#MapImage))
	CloseGadgetList()

	ComboBoxGadget(#AreaSelection, 0, ToolBarHeight(#ToolBar), 150, 20)
	ButtonGadget(#NewArea, 150, ToolBarHeight(#ToolBar), 50, 20, "New")
	ListIconGadget(#PointList, 0, ToolBarHeight(#ToolBar) + 20, 200, 0, "X", 50, #PB_ListIcon_FullRowSelect)
	AddGadgetColumn(#PointList, 1, "Y", 50)
	ButtonGadget(#DeleteArea, 0, 0, 200, 20, "Delete area")
	
	AddKeyboardShortcut(#Window, #PB_Shortcut_Control | #PB_Shortcut_S, #Save)
	AddKeyboardShortcut(#Window, #PB_Shortcut_Delete, #DeleteCurrentPoint)

	SetGadgetAttribute(#MapCanvas, #PB_Canvas_Cursor, #PB_Cursor_Cross)
	LoadAreas()
	UpdateImage()
	Repeat
		Select WaitWindowEvent()
			Case #PB_Event_Menu
				Select EventMenu()
					Case #Save
						If SaveAreas()
							MessageRequester("Save", "Areas saved", #MB_ICONINFORMATION)
						Else
							MessageRequester("Save", "Saving failed!", #MB_ICONERROR)
						EndIf
					Case #DeleteCurrentPoint
						item = GetGadgetState(#PointList)
						If item <> -1
							SelectElement(Areas()\points(), item)
							DeleteElement(Areas()\points())
							fileChanged = #True
							UpdateImage()
						EndIf
				EndSelect
			Case #PB_Event_Gadget
				Select EventGadget()
					Case #AreaSelection
						If EventType() = #PB_EventType_Change
							item = GetGadgetState(#AreaSelection)
							If item <> -1
								SelectElement(Areas(), item)
								SetWindowTitle(#Window, #Title + " [" + Areas()\name + "]")
								UpdateImage()
							EndIf
						EndIf
					Case #NewArea
						If OpenWindow(#NewArea_Window, 100, 100, 280, 110, #Title + " - New area", #PB_Window_SystemMenu | #PB_Window_WindowCentered, WindowID(#Window))
							DisableWindow(#Window, #True)
							TextGadget(#NewArea_Text1, 10, 10, 50, 20, "Name:")
							TextGadget(#NewArea_Text2, 10, 40, 50, 20, "Type:")
							StringGadget(#NewArea_Name, 70, 10, 200, 20, "")
							ComboBoxGadget(#NewArea_Type, 70, 40, 200, 20)
							AddGadgetItem(#NewArea_Type, -1, "drift")
							ButtonGadget(#NewArea_OK, 90, 70, 100, 30, "OK")
						EndIf
					Case #PointList
						If EventType() = #PB_EventType_Change
							UpdateImage()
						EndIf
					Case #DeleteArea
						item = GetGadgetState(#AreaSelection)
						If item = -1
							MessageRequester("Delete area", "Please select an area first!", #MB_ICONERROR)
						Else
							SelectElement(Areas(), item)
							If MessageRequester("Delete area", "Delete the selected area '" + Areas()\name + "' and all it's " + Str(ListSize(Areas()\points())) + " points?", #MB_YESNO | #MB_ICONWARNING) = #PB_MessageRequester_Yes
								DeleteElement(Areas())
								fileChanged = #True
								UpdateAreaSelectBox()
								If item >= CountGadgetItems(#AreaSelection)
									item = CountGadgetItems(#AreaSelection) - 1
								EndIf
								SetGadgetState(#AreaSelection, item)
								SetWindowTitle(#Window, #Title + " [" + Areas()\name + "]")
								UpdateImage()
							EndIf
						EndIf
					Case #NewArea_OK
						name$ = Trim(GetGadgetText(#NewArea_Name))
						type$ = GetGadgetText(#NewArea_Type)
						If name$ And type$
							LastElement(Areas())
							AddElement(Areas())
							Areas()\name = name$
							Areas()\type = type$
							fileChanged = #True
							UpdateAreaSelectBox()
							SetGadgetState(#AreaSelection, CountGadgetItems(#AreaSelection) - 1)
							SetWindowTitle(#Window, #Title + " [" + Areas()\name + "]")
							UpdateImage()
							CloseWindow(#NewArea_Window)
							DisableWindow(#Window, #False)
						Else
							MessageRequester(#Title, "Please enter a name and select a type!", #MB_ICONERROR)
						EndIf
					Case #MapCanvas
						event = EventType()
						If event = #PB_EventType_LeftClick Or event = #PB_EventType_RightClick
							If GetGadgetState(#AreaSelection) = -1
								MessageRequester(#Title, "Please select an area first!", #MB_ICONERROR)
							Else
								point.Point
								point\x = GetGadgetAttribute(#MapCanvas, #PB_Canvas_MouseX) - 3000
								point\y = (GetGadgetAttribute(#MapCanvas, #PB_Canvas_MouseY) - 3000) * -1
								Select event
									Case #PB_EventType_LeftClick
										item = GetGadgetState(#PointList)
										If item = -1
											LastElement(Areas()\points())
										Else
											SelectElement(Areas()\points(), item)
										EndIf
										AddElement(Areas()\points())
										Areas()\points() = point
										fileChanged = #True
										UpdateImage()
									Case #PB_EventType_RightClick
										nearestPoint = -1
										ForEach Areas()\points()
											distance = Abs(GetDistanceBetweenPoints(Areas()\points(), point))
											If nearestPoint = -1 Or distance < nearestDistance
												nearestPoint = ListIndex(Areas()\points())
												nearestDistance = distance
											EndIf
										Next
										If nearestPoint <> -1 And nearestDistance < 10
											SelectElement(Areas()\points(), nearestPoint)
											DeleteElement(Areas()\points())
											fileChanged = #True
											UpdateImage()
										EndIf
								EndSelect
							EndIf
						EndIf
				EndSelect
			Case #PB_Event_SizeWindow
				ResizeGadget(#ScrollArea, #PB_Ignore, #PB_Ignore, WindowWidth(#Window) - GadgetWidth(#PointList), WindowHeight(#Window))
				ResizeGadget(#AreaSelection, WindowWidth(#Window) - GadgetWidth(#AreaSelection) - GadgetWidth(#NewArea), #PB_Ignore, #PB_Ignore, #PB_Ignore)
				ResizeGadget(#NewArea, WindowWidth(#Window) - GadgetWidth(#NewArea), #PB_Ignore, #PB_Ignore, #PB_Ignore)
				ResizeGadget(#PointList, WindowWidth(#Window) - GadgetWidth(#PointList), #PB_Ignore, #PB_Ignore, WindowHeight(#Window) - GadgetY(#PointList) - GadgetHeight(#DeleteArea))
				ResizeGadget(#DeleteArea, WindowWidth(#Window) - GadgetWidth(#DeleteArea), WindowHeight(#Window) - GadgetHeight(#DeleteArea), #PB_Ignore, #PB_Ignore)
			Case #PB_Event_CloseWindow
				Select EventWindow()
					Case #Window
						If fileChanged
							Select MessageRequester("Unsaved changes", "There are unsaved changes!" + Chr(13) + Chr(13) + "Do you want to save before quit?", #MB_YESNOCANCEL | #MB_ICONQUESTION)
								Case #PB_MessageRequester_Yes
									If SaveAreas()
										Break
									Else
										MessageRequester("Save", "Saving failed!" + Chr(13) + Chr(13) + "Click OK to go back without exiting the application.", #MB_ICONERROR)
									EndIf
								Case #PB_MessageRequester_No
									Break
							EndSelect
						Else
							Break
						EndIf
					Case #NewArea_Window
						CloseWindow(#NewArea_Window)
						DisableWindow(#Window, #False)
				EndSelect
		EndSelect
	ForEver
EndIf