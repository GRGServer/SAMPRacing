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
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\Includes Updater.exe" + Chr(34))
			WriteStringN(File, "cd " + Chr(34) + ServerRoot$ + "gamemodes" + Chr(34))
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\pawn\pawncc.exe" + Chr(34) + " grgserver.pwn " + Chr(34) + "-i" + ServerRoot$ + "includes" + Chr(34) + " -; -(")
			WriteStringN(File, "::Todo Finder")
			WriteStringN(File, "NPP_SAVE")
			WriteStringN(File, Chr(34) + ServerRoot$ + "tools\Todo Finder.exe" + Chr(34))
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
; IDE Options = PureBasic 5.21 LTS (Windows - x86)
; CursorPosition = 59
; FirstLine = 30
; Folding = -
; EnableXP
; EnableAdmin
; UseIcon = NPP Customizer.ico
; Executable = NPP Customizer.exe
; EnableCompileCount = 21
; EnableBuildCount = 14
; EnableExeConstant
; IncludeVersionInfo
; VersionField0 = 1,0,0,0
; VersionField1 = 1,0,0,0
; VersionField2 = SelfCoders
; VersionField3 = Notepad++ Customizer
; VersionField4 = 1.0
; VersionField5 = 1.0
; VersionField6 = Notepad++ Customizer
; VersionField7 = Notepad++ Customizer
; VersionField8 = %EXECUTABLE
; VersionField13 = nppcustomizer@selfcoders.com
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