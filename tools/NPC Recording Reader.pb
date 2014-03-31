#SAMP_NPCREC_FILEID_0_3d_v1 = $E8030000
#SAMP_NPCREC_FILEID_0_3d_v2 = $0D1000
#SAMP_NPCREC_FILEID_0_3z = $03E8

serverRoot$ = ProgramParameter()
If serverRoot$ = ""
	mainPath$ = GetPathPart(ProgramFilename())
	serverRoot$ = GetPathPart(Left(mainPath$, Len(mainPath$) - 1))
EndIf

path$ = serverRoot$ + "npcmodes/recordings"

If OpenConsole("NPC Recording Reader")
	dir = ExamineDirectory(#PB_Any, path$, "*.rec")
	If IsDirectory(dir)
		While NextDirectoryEntry(dir)
			If DirectoryEntryType(dir) = #PB_DirectoryEntry_File
				name$ = DirectoryEntryName(dir)
				file = ReadFile(#PB_Any, path$ + "/" + name$)
				If IsFile(file)
					PrintN(name$ + ":")
					fileIdentifier = ReadLong(file)
					If fileIdentifier = #SAMP_NPCREC_FILEID_0_3d_v1 Or fileIdentifier = #SAMP_NPCREC_FILEID_0_3d_v2 Or fileIdentifier = #SAMP_NPCREC_FILEID_0_3z
						Select ReadLong(file)
							Case 1; Driver
								PrintN("  Recording type: Driver")
								FileSeek(file, 28, #PB_Relative)
								x.f = ReadFloat(file)
								y.f = ReadFloat(file)
								z.f = ReadFloat(file)
								PrintN("  Spawn position:")
								PrintN("    X: " + StrF(x))
								PrintN("    Y: " + StrF(y))
								PrintN("    Z: " + StrF(z))
							Case 2; On foot
								PrintN("  Recording type: On foot")
								FileSeek(file, 10, #PB_Relative)
								x.f = ReadFloat(file)
								y.f = ReadFloat(file)
								z.f = ReadFloat(file)
								PrintN("  Spawn position:")
								PrintN("    X: " + StrF(x))
								PrintN("    Y: " + StrF(y))
								PrintN("    Z: " + StrF(z))
						EndSelect
					Else
						PrintN("  Invalid file identifier (" + Hex(fileIdentifier) + ")!")
					EndIf
					PrintN("")
					CloseFile(file)
				EndIf
			EndIf
		Wend
		FinishDirectory(dir)
	EndIf
	CloseConsole()
EndIf