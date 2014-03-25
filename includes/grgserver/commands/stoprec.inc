PCMD:stoprec[ISADMIN](playerID, params[], StringID:193("Stop the current NPC recording"))
{
	StopRecordingPlayerData(playerID);
	SendClientMessageEx(playerID, COLOR_INFO, StringID:194("Recording stopped"));
	return COMMAND_OK;
}