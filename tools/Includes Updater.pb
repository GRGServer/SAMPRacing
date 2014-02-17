Global grgIncludesPath$
Global mainInclude

Procedure AddIncludeGroup(name$)
	WriteStringN(mainInclude, "// " + name$)
EndProcedure

Procedure AddInclude(fileName$)
	WriteStringN(mainInclude, "#include <grgserver\" + fileName$ + ">")
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
			AddInclude(directoryName$ + "\" + Includes())
		Next
		WriteStringN(mainInclude, "")
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
			WriteStringN(mainInclude, "")
			AddDir("Structures")
			AddIncludeGroup("Global variables")
			AddInclude("arrays.inc")
			AddInclude("globals.inc")
			WriteStringN(mainInclude, "")
			AddDir("Functions")
			AddDir("Callbacks")
			AddDir("Dialogs")
			AddDir("Pickups")
			AddDir("Timers")
			AddDir("Commands")
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
; IDE Options = PureBasic 5.21 LTS (Windows - x86)
; ExecutableFormat = Console
; CursorPosition = 58
; FirstLine = 18
; Folding = -
; EnableXP
; UseIcon = Includes Updater.ico
; Executable = Includes Updater.exe
; EnableCompileCount = 16
; EnableBuildCount = 16
; EnableExeConstant
; IncludeVersionInfo
; VersionField0 = 1,0,0,0
; VersionField1 = 1,0,0,0
; VersionField2 = SelfCoders
; VersionField3 = Includes Updater
; VersionField4 = 1.0
; VersionField5 = 1.0
; VersionField6 = Includes Updater
; VersionField7 = Includes Updater
; VersionField8 = %EXECUTABLE
; VersionField13 = includesupdater@selfcoders.com
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