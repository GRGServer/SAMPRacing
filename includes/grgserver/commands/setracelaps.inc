PCMD:setracelaps[ISADMIN](playerID, params[], StringID:164("Set the number of laps of a race"))
{
	new raceID;
	new laps;
	if (sscanf(params, "dd", raceID, laps))
	{
		CmdUsageMsg(playerID, "addracecp", "RaceID", "Laps");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	if (laps < 1)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:165("The number of laps can not be bellow 1!"));
		return COMMAND_ERROR;
	}

	g_races[raceID][E_RACE_LAPS] = laps;

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:166("The number of laps of the race has been changed"));

	return COMMAND_OK;
}