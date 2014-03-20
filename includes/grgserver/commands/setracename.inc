PCMD:setracename[ISADMIN](playerID, params[], StringID:162("Set the name of a race"))
{
	new raceID;
	new name[STRINGLENGTH_RACENAME];
	if (sscanf(params, "ds[" #STRINGLENGTH_RACENAME "]", raceID, name))
	{
		CmdUsageMsg(playerID, "addracecp", "RaceID", "Name");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	g_races[raceID][E_RACE_NAME] = name;

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:163("The name of the race has been changed"));

	return COMMAND_OK;
}