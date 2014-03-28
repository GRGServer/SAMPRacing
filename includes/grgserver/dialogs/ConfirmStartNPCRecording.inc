ShowDialog:ConfirmStartNPCRecording(playerID)
{
	new info[1024];
	new recordingTypeString[10];

	switch (PVar:playerID[RECNPC_TYPE])
	{
		case PLAYER_RECORDING_TYPE_DRIVER:
		{
			strcat(recordingTypeString, LanguageString(playerID, StringID:194("Driver")));
		}
		case PLAYER_RECORDING_TYPE_ONFOOT:
		{
			strcat(recordingTypeString, LanguageString(playerID, StringID:195("On foot")));
		}
	}

	strcat(info, LanguageString(playerID, StringID:196("Your NPC recording is ready to start.")));
	strcat(info, "\n\n");
	Format:info("%s%s: %s\n", info, LanguageString(playerID, StringID:197("Name")), PVar:playerID[RECNPC_NAME]);
	Format:info("%s%s: %s", info, LanguageString(playerID, StringID:198("Type")), recordingTypeString);

	new npcList[200];
	Count(playNPCIndex, MAX_RECNPC_PLAYNPCS)
	{
		new npcID = PVar:playerID[RECNPC_PLAYNPCS][playNPCIndex];
		if (npcID != -1)
		{
			ConcatString(npcList, g_npcs[npcID][E_NPC_RECORDING_NAME], ", ");
		}
	}

	if (StrNotNull(npcList))
	{
		strcat(info, "\n");
		Format:info("%s%s: %s", info, LanguageString(playerID, StringID:199("NPCs")), npcList);
	}

	CreateDialog(playerID, "ConfirmStartNPCRecording", DIALOG_STYLE_MSGBOX, LanguageString(playerID, StringID:200("Start NPC recording")), info, LanguageString(playerID, StringID:173("Start")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:ConfirmStartNPCRecording(playerID, response, listItem, inputText[])
{
	if (response)
	{
		PVar:playerID[RECNPC_RUNNING] = true;
		StartRecordingPlayerData(playerID, PVar:playerID[RECNPC_TYPE], PVar:playerID[RECNPC_NAME]);

		Count(playNPCIndex, MAX_RECNPC_PLAYNPCS)
		{
			new npcID = PVar:playerID[RECNPC_PLAYNPCS][playNPCIndex];
			if (npcID != -1)
			{
				FormatNew:name[MAX_PLAYER_NAME]("NPC_%d", npcID);
				new npcPlayerID = GetPlayerID(name);
				if (npcPlayerID != INVALID_PLAYER_ID)
				{
					SetPlayerVirtualWorld(npcPlayerID, GetPlayerVirtualWorld(playerID));
					SetVehicleVirtualWorld(npcPlayerID, GetPlayerVirtualWorld(playerID));
					SendNPCCommand(npcPlayerID, NPCCMD_START);
				}
			}
		}

		SendClientMessageEx(playerID, COLOR_INFO, StringID:201("NPC recording started"));
		SendClientMessageEx(playerID, COLOR_INFO, StringID:203("Press %s to stop the recording"), GetGameTextKeyByID(KEY_RECNPC_STOP, IsPlayerInAnyVehicle(playerID)));
	}
	else
	{
		Count(playNPCIndex, MAX_RECNPC_PLAYNPCS)
		{
			new npcID = PVar:playerID[RECNPC_PLAYNPCS][playNPCIndex];
			if (npcID != -1)
			{
				FormatNew:name[MAX_PLAYER_NAME]("NPC_%d", npcID);
				new npcPlayerID = GetPlayerID(name);
				if (npcPlayerID != INVALID_PLAYER_ID)
				{
					SetPlayerVirtualWorld(npcPlayerID, VIRTUALWORLD_IDLENPC);
					SendNPCCommand(npcPlayerID, NPCCMD_STOP);
				}
			}
		}
	}
}