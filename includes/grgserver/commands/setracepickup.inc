PCMD:setracepickup[ISADMIN](playerID, params[], StringID:206("Set the pickup for a race"))
{
	new raceID;
	if (sscanf(params, "d", raceID))
	{
		CmdUsageMsg(playerID, "setracepickup", "RaceID");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	GetPlayerPos(playerID, g_races[raceID][E_RACE_PICKUP_POSX], g_races[raceID][E_RACE_PICKUP_POSY], g_races[raceID][E_RACE_PICKUP_POSZ]);

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:207("The pickup position of race %d (%s) has been set"), raceID, g_races[raceID][E_RACE_NAME]);

	return COMMAND_OK;
}