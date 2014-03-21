Global grgIncludesPath$
Global mainInclude

Procedure AddIncludeGroup(name$)
	WriteString(mainInclude, "// " + name$ + #LF$)
EndProcedure

Procedure AddInclude(fileName$)
	WriteString(mainInclude, "#include <grgserver/" + fileName$ + ">" + #LF$)
EndProcedure

Procedure AddDir(directoryName$)
	NewList Includes.s()
	directory = ExamineDirectory(#PB_Any, grgIncludesPath$ + directoryName$, "*.inc")
	If IsDirectory(directory)
		While NextDirectoryEntry(directory)
			If DirectoryEntryType(directory) = #PB_DirectoryEntry_File
				AddElement(Includes())
				Includes() = DirectoryEntryName(directory)
			EndIf
		Wend
		SortList(Includes(), #PB_Sort_Ascending)
		AddIncludeGroup(directoryName$)
		ForEach Includes()
			AddInclude(directoryName$ + "/" + Includes())
		Next
		WriteString(mainInclude, #LF$)
		FinishDirectory(directory)
	EndIf
EndProcedure

mainPath$ = GetPathPart(ProgramFilename())
serverRoot$ = GetPathPart(Left(mainPath$, Len(mainPath$) - 1))
grgIncludesPath$ = serverRoot$ + "includes\grgserver\"

If OpenConsole()
	directory = ExamineDirectory(#PB_Any, grgIncludesPath$, "*.*")
	If IsDirectory(directory)
		Print("Updating includes in '" +grgIncludesPath$ + "'...")
		mainInclude = CreateFile(#PB_Any, grgIncludesPath$ + "main.inc")
		If IsFile(mainInclude)
			AddIncludeGroup("Constants")
			AddInclude("localconfig.inc")
			AddInclude("constants.inc")
			AddInclude("macros.inc")
			WriteString(mainInclude, #LF$)
			AddDir("structures")
			AddIncludeGroup("Global variables")
			AddInclude("globals.inc")
			AddInclude("forwards.inc")
			WriteString(mainInclude, #LF$)
			AddDir("functions")
			AddDir("callbacks")
			AddDir("dialogs")
			AddDir("pickups")
			AddDir("timers")
			AddDir("commands")
			CloseFile(mainInclude)
			Print(" Done")
		Else
			Print(" Failed")
			PrintN("Can not create main.inc in " +grgIncludesPath$ + "!")
		EndIf
		FinishDirectory(directory)
	Else
		PrintN("The includes path '" +grgIncludesPath$ + "' does not exist!")
	EndIf
EndIf