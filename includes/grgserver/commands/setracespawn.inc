PCMD:setracespawn[ISADMIN](playerID, params[], StringID:192("Set a spawn location of a race"))
{
	new raceID;
	new spawn;
	if (sscanf(params, "dd", raceID, spawn))
	{
		CmdUsageMsg(playerID, "setracespawn", "RaceID", "SpawnNumber");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	if (spawn < 0 || spawn >= RACE_PLAYERCOUNT)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:204("The spawn must be between 0 and %d!"), RACE_PLAYERCOUNT - 1);
		return COMMAND_ERROR;
	}

	if (!IsPlayerInAnyVehicle(playerID))
	{
		return COMMAND_NOT_IN_VEHICLE;
	}

	new vehicleID = GetPlayerVehicleID(playerID);

	GetVehiclePos(vehicleID, g_races[raceID][E_RACE_SPAWN_POSX][spawn], g_races[raceID][E_RACE_SPAWN_POSY][spawn], g_races[raceID][E_RACE_SPAWN_POSZ][spawn]);
	GetVehicleZAngle(vehicleID, g_races[raceID][E_RACE_SPAWN_ANGLE][spawn]);

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:205("Spawn %d of race %d (%s) has been set"), spawn, raceID, g_races[raceID][E_RACE_NAME]);

	return COMMAND_OK;
}