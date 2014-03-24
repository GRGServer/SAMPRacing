ShowRaceCheckpoint(playerID, raceID, checkpointID)
{
	new Float:nextX;
	new Float:nextY;
	new Float:nextZ;

	new nextCheckpointID = checkpointID + 1;

	new type = 0;// Type 0 = normal checkpoint

	if (nextCheckpointID >= MAX_RACECHECKPOINTS || (!g_races[raceID][E_RACE_CHECKPOINT_POSX][nextCheckpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSY][nextCheckpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSZ][nextCheckpointID]))
	{
		if (PVar:playerID[RACE_LAP] < g_races[raceID][E_RACE_LAPS])
		{
			nextX = g_races[raceID][E_RACE_CHECKPOINT_POSX][0];
			nextY = g_races[raceID][E_RACE_CHECKPOINT_POSY][0];
			nextZ = g_races[raceID][E_RACE_CHECKPOINT_POSZ][0];
		}
		else
		{
			type = 1;// Type 1 = Finish checkpoint
		}
	}
	else
	{
		nextX = g_races[raceID][E_RACE_CHECKPOINT_POSX][nextCheckpointID];
		nextY = g_races[raceID][E_RACE_CHECKPOINT_POSY][nextCheckpointID];
		nextZ = g_races[raceID][E_RACE_CHECKPOINT_POSZ][nextCheckpointID];
	}

	PVar:playerID[RACE_ID] = raceID;
	PVar:playerID[RACE_CHECKPOINTID] = checkpointID;

	new checkpoints;
	Count(checkpointIndex, MAX_RACECHECKPOINTS)
	{
		if (g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointIndex] || g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointIndex] || g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointIndex])
		{
			checkpoints++;
		}
		else
		{
			break;
		}
	}

	SetPlayerRaceCheckpoint(playerID, type, g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointID], g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointID], g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointID], nextX, nextY, nextZ, RACE_CHECKPOINT_SIZE);

	// Show the bottom line if this is not the first (start) checkpoint
	if (PVar:playerID[RACE_LAP] > 1 || checkpointID || GetPlayerVehicleSeat(playerID) > 0)
	{
		FormatNew:string[100](LanguageString(playerID, StringID:168("%s~n~~n~Lap %d / %d * Checkpoint %d / %d")), g_races[raceID][E_RACE_NAME], PVar:playerID[RACE_LAP], g_races[raceID][E_RACE_LAPS], checkpointID + 1, checkpoints);
		PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_RACE_BOTTOM], string);
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACE_BOTTOM]);
	}
	else
	{
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACE_BOTTOM]);
	}
}