PCMD:setnpcrecording[ISADMIN](playerID, params[], StringID:184("Set the recording of a NPC"))
{
	new npcPlayerID;
	new recordingName[STRINGLENGTH_NPCRECORDINGNAME];
	new recordingTypeString[10];
	if (sscanf(params, "us[" #STRINGLENGTH_NPCRECORDINGNAME "]s[10]", npcPlayerID, recordingName, recordingTypeString))
	{
		CmdUsageMsg(playerID, "setnpcrecording", "NPC", "Recording", "Type(driver/foot)");
		return COMMAND_USAGE;
	}

	if (npcPlayerID == INVALID_PLAYER_ID || !IsPlayerNPC(npcPlayerID))
	{
		return COMMAND_PLAYER_NOT_FOUND;
	}

	new recordingType;
	if (IsStr(recordingTypeString, "driver"))
	{
		recordingType = PLAYER_RECORDING_TYPE_DRIVER;
	}
	else if (IsStr(recordingTypeString, "foot"))
	{
		recordingType = PLAYER_RECORDING_TYPE_ONFOOT;
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:185("Invalid recording type!"));
		return COMMAND_ERROR;
	}

	PVar:npcPlayerID[NPC_RECORDING_NAME] = recordingName;
	PVar:npcPlayerID[NPC_RECORDING_TYPE] = recordingType;

	SendClientMessageEx(playerID, COLOR_INFO, StringID:186("The recording of the NPC has been changed"));
	return COMMAND_OK;
}