PCMD:setracescore[ISADMIN](playerID, params[], StringID:178("Set the number of Score of a race"))
{
	new raceID;
	new score;
	if (sscanf(params, "dd", raceID, score))
	{
		CmdUsageMsg(playerID, "addracecp", "RaceID", "Score");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	if (score < 1)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:180("The number of Score can not be bellow 1!"));
		return COMMAND_ERROR;
	}

	g_races[raceID][E_RACE_SCORE] = score;

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:181("The number of score of the race has been changed"));

	return COMMAND_OK;
}