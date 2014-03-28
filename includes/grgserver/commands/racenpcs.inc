PCMD:racenpcs[ISADMIN](playerID, params[], StringID:189("Show which NPCs are assigned to a specific race"))
{
	new raceID;
	if (sscanf(params, "d", raceID))
	{
		CmdUsageMsg(playerID, "racenpcs", "RaceID");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:190("NPCs assigned to race %d (%s):"), raceID, g_races[raceID][E_RACE_NAME]);

	new npcs;
	Count(npcIndex, MAX_RACENPCS)
	{
		new npcID = g_races[raceID][E_RACE_NPCS][npcIndex];
		if (npcID != -1)
		{
			FormatNew:string[100]("%d - %s", npcID, g_npcs[npcID][E_NPC_RECORDING_NAME]);
			SendClientMessage(playerID, COLOR_INFO, string);
			npcs++;
		}
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:191("%d NPCs"), npcs);

	return COMMAND_OK;
}