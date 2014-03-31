public OnPlayerEnterRaceCheckpoint(playerid)
{
	if (!IsPlayerInAnyVehicle(playerid))
	{
		GameTextForPlayer(playerid, LanguageString(playerid, StringID:14("You are not in a vehicle!")), 3000, 3);
		return true;
	}

	DisablePlayerRaceCheckpoint(playerid);

	new raceID = PVar:playerid[RACE_ID];
	new nextCheckpointID = PVar:playerid[RACE_CHECKPOINTID] + 1;

	if (nextCheckpointID >= MAX_RACECHECKPOINTS || (!g_races[raceID][E_RACE_CHECKPOINT_POSX][nextCheckpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSY][nextCheckpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSZ][nextCheckpointID]))
	{
		if (PVar:playerid[RACE_LAP] < g_races[raceID][E_RACE_LAPS])
		{
			PVar:playerid[RACE_LAP]++;
			nextCheckpointID = 0;

			FormatNew:string[100](LanguageString(playerid, StringID:159("Lap %d / %d")), PVar:playerid[RACE_LAP], g_races[raceID][E_RACE_LAPS]);
			GameTextForPlayer(playerid, string, 3000, 3);
		}
		else
		{
			GameTextForPlayer(playerid, LanguageString(playerid, StringID:167("Finish!")), 3000, 3);

			EndRace(playerid);

			return true;
		}
	}

	ShowRaceCheckpoint(playerid, PVar:playerid[RACE_ID], nextCheckpointID);

	return true;
}