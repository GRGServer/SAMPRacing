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
									search$ = "// TODO"
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