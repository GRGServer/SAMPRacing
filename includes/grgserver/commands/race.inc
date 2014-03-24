CMD:race(playerID, params[], StringID:156("Start a race"))
{
	new raceID;
	if (sscanf(params, "d", raceID))
	{
		CmdUsageMsg(playerID, "race", "RaceID");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	if (GetPlayerScore(playerID) < g_races[raceID][E_RACE_LEVEL])
	{
		GameTextForPlayer(playerID, LanguageString(playerID, StringID:179("You do not have the required level!")), 3000, 3);
		return COMMAND_ERROR;
	}

	PVar:playerID[RACE_LAP] = 1;

	ShowRaceCheckpoint(playerID, raceID, 0);

	return COMMAND_OK;
}