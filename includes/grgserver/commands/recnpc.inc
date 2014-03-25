PCMD:recnpc[ISADMIN](playerID, params[], StringID:187("Record a new NPC and optionally playback other NPCs"))
{
	new name[STRINGLENGTH_NPCRECORDINGNAME];
	new playNPCs[200];
	if (sscanf(params, "s[" #STRINGLENGTH_NPCRECORDINGNAME "]s[200]", name, playNPCs))
	{
		if (sscanf(params, "s[" #STRINGLENGTH_NPCRECORDINGNAME "]", name))
		{
			CmdUsageMsg(playerID, "recnpc", "Name", "[NPC1]", "[NPC2]", "[...]");
			return COMMAND_USAGE;
		}
	}

	new recordingType;
	if (IsPlayerInAnyVehicle(playerID))
	{
		recordingType = PLAYER_RECORDING_TYPE_DRIVER;
	}
	else
	{
		recordingType = PLAYER_RECORDING_TYPE_ONFOOT;
	}

	new playNPCsArray[MAX_RECNPC_PLAYNPCS][MAX_PLAYER_NAME];
	explode(playNPCs, playNPCsArray);

	Foreach(npcIndex, playNPCsArray)
	{
		new npcPlayerID = INVALID_PLAYER_ID;
		sscanf(playNPCsArray[npcIndex], "u", npcPlayerID);

		if (npcPlayerID != INVALID_PLAYER_ID)
		{
			SendNPCCommand(npcPlayerID, NPCCMD_START);
		}
	}

	StartRecordingPlayerData(playerID, recordingType, name);

	return COMMAND_OK;
}