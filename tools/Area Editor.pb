Enumeration
	#MapImage
	#MergedImage
	#Window
	#ScrollArea
	#MapCanvas
	#AreaSelection
	#NewArea
	#PointList
	#NewArea_Window
	#NewArea_Text1
	#NewArea_Text2
	#NewArea_Text3
	#NewArea_Name
	#NewArea_Group
	#NewArea_Type
	#NewArea_OK
EndEnumeration

#Title = "Area Editor"

Structure Area
	name.s
	group.s
	type.s
	List points.Point()
EndStructure

Global scriptFilesPath$
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
		AddGadgetItem(#AreaSelection, -1, Areas()\name)
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
					Areas()\group = GetXMLAttribute(*areaNode, "group")
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
				UpdateAreaSelectBox()
			Else
				MessageRequester(#Title, "No main node found in XML file!", #MB_ICONERROR)
			EndIf
		Else
			MessageRequester(#Title, "Can not load XML file!" + Chr(13) + Chr(13) + "Message: " + XMLError(xml) + Chr(13) + "Line: " + Str(XMLErrorLine(xml)) + Chr(13) + "Character: " + Str(XMLErrorPosition(xml)), #MB_ICONERROR)
		EndIf
	EndIf
EndProcedure

Procedure LoadSelectedArea()
	item = GetGadgetState(#AreaSelection)
	If item <> -1
		SelectElement(Areas(), item)
		SetWindowTitle(#Window, #Title + " [" + Areas()\name + "]")
		UpdateImage()
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
	ScrollAreaGadget(#ScrollArea, 0, 20, 0, 0, ImageWidth(#MapImage), ImageHeight(#MapImage), 100, #PB_ScrollArea_Center)
	CanvasGadget(#MapCanvas, 0, 0, ImageWidth(#MapImage), ImageHeight(#MapImage))
	CloseGadgetList()

	ComboBoxGadget(#AreaSelection, 0, 0, 150, 20)
	ButtonGadget(#NewArea, 150, 0, 50, 20, "New")
	ListIconGadget(#PointList, 0, 20, 200, 0, "X", 50, #PB_ListIcon_FullRowSelect)
	AddGadgetColumn(#PointList, 1, "Y", 50)

	SetGadgetAttribute(#MapCanvas, #PB_Canvas_Cursor, #PB_Cursor_Cross)
	LoadAreas()
	UpdateImage()
	Repeat
		Select WaitWindowEvent()
			Case #PB_Event_Gadget
				Select EventGadget()
					Case #AreaSelection
						If EventType() = #PB_EventType_Change
							LoadSelectedArea()
						EndIf
					Case #NewArea
						If OpenWindow(#NewArea_Window, 100, 100, 280, 140, #Title + " - New area", #PB_Window_SystemMenu | #PB_Window_WindowCentered, WindowID(#Window))
							DisableWindow(#Window, #True)
							TextGadget(#NewArea_Text1, 10, 10, 50, 20, "Name:")
							TextGadget(#NewArea_Text2, 10, 40, 50, 20, "Group:")
							TextGadget(#NewArea_Text3, 10, 70, 50, 20, "Type:")
							StringGadget(#NewArea_Name, 70, 10, 200, 20, "")
							ComboBoxGadget(#NewArea_Group, 70, 40, 200, 20)
							ComboBoxGadget(#NewArea_Type, 70, 70, 200, 20)
							ButtonGadget(#NewArea_OK, 90, 100, 100, 30, "OK")
						EndIf
					Case #PointList
						If EventType() = #PB_EventType_Change
							UpdateImage()
						EndIf
					Case #NewArea_OK
						name$ = Trim(GetGadgetText(#NewArea_Name))
						If name$
							AddElement(Areas())
							Areas()\name = name$
							Areas()\group = GetGadgetText(#NewArea_Group)
							Areas()\type = GetGadgetText(#NewArea_Type)
							UpdateAreaSelectBox()
							SetGadgetState(#AreaSelection, CountGadgetItems(#AreaSelection) - 1)
							LoadSelectedArea()
							CloseWindow(#NewArea_Window)
							DisableWindow(#Window, #False)
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
											UpdateImage()
										EndIf
								EndSelect
							EndIf
						EndIf
				EndSelect
			Case #PB_Event_SizeWindow
				ResizeGadget(#ScrollArea, 0, 0, WindowWidth(#Window) - GadgetWidth(#PointList), WindowHeight(#Window))
				ResizeGadget(#AreaSelection, WindowWidth(#Window) - GadgetWidth(#AreaSelection) - GadgetWidth(#NewArea), #PB_Ignore, #PB_Ignore, #PB_Ignore)
				ResizeGadget(#NewArea, WindowWidth(#Window) - GadgetWidth(#NewArea), #PB_Ignore, #PB_Ignore, #PB_Ignore)
				ResizeGadget(#PointList, WindowWidth(#Window) - GadgetWidth(#PointList), #PB_Ignore, #PB_Ignore, WindowHeight(#Window) - GadgetY(#PointList))
			Case #PB_Event_CloseWindow
				Select EventWindow()
					Case #Window
						Break
					Case #NewArea_Window
						CloseWindow(#NewArea_Window)
						DisableWindow(#Window, #False)
				EndSelect
		EndSelect
	ForEver
EndIf