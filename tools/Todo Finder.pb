Procedure ScanDir(path$)
	directory = ExamineDirectory(#PB_Any, path$, "*.*")
	If IsDirectory(directory)
		While NextDirectoryEntry(directory)
			name$ = DirectoryEntryName(directory)
			If name$ <> "." And name$ <> ".."
				Select DirectoryEntryType(directory)
					Case #PB_DirectoryEntry_Directory
						ScanDir(path$ + name$ + "\")
					Case #PB_DirectoryEntry_File
						If LCase(GetExtensionPart(name$)) = "inc" Or LCase(GetExtensionPart(name$)) = "pwn"
							file$ = path$ + name$
							file = ReadFile(#PB_Any, file$)
							If IsFile(file)
								lineNo = 0
								Repeat
									lineNo + 1
									line$ = RemoveString(ReadString(file), Chr(9))
									search$ = "// TODO:"
									position = FindString(line$, search$, 1, #PB_String_NoCase)
									If position
										position + Len(search$)
										PrintN(file$ + "(" + Str(lineNo) + ") : todo " + Trim(Mid(line$, position)))
									EndIf
								Until Eof(file)
								CloseFile(file)
							EndIf
						EndIf
				EndSelect
			EndIf
		Wend
		FinishDirectory(directory)
	EndIf
EndProcedure

serverRoot$ = ProgramParameter()
If serverRoot$ = ""
	mainPath$ = GetPathPart(ProgramFilename())
	serverRoot$ = GetPathPart(Left(mainPath$, Len(mainPath$) - 1))
EndIf

If OpenConsole("Todo Finder")
	ScanDir(serverRoot$)
EndIf
; IDE Options = PureBasic 5.11 (Windows - x86)
; CursorPosition = 21
; Folding = -
; EnableXP
; UseIcon = Todo Finder.ico
; Executable = Todo Finder.exe
; EnableCompileCount = 17
; EnableBuildCount = 13
; EnableExeConstant
; IncludeVersionInfo
; VersionField0 = 1,0,0,0
; VersionField1 = 1,0,0,0
; VersionField2 = SelfCoders
; VersionField3 = Todo Finder
; VersionField4 = 1.0
; VersionField5 = 1.0
; VersionField6 = Todo Finder
; VersionField7 = Todo Finder
; VersionField8 = %EXECUTABLE
; VersionField13 = todofinder@selfcoders.com
; VersionField14 = http://www.selfcoders.com
; VersionField15 = VOS_NT_WINDOWS32
; VersionField16 = VFT_APP
; VersionField18 = Build
; VersionField19 = Compile OS
; VersionField20 = Date
; VersionField21 = %BUILDCOUNT
; VersionField22 = %OS
; VersionField23 = %y-%m-%d %h:%i:%s