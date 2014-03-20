PCMD:addracecp[ISADMIN](playerID, params[], StringID:158("Add a new checkpoint to a race"))
{
	new raceID;
	if (sscanf(params, "d", raceID))
	{
		CmdUsageMsg(playerID, "addracecp", "RaceID");
		return COMMAND_USAGE;
	}

	if (raceID < 0 || raceID >= MAX_RACES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
		return COMMAND_ERROR;
	}

	new unusedCheckpointID = -1;
	Foreach(checkpointID, g_races[])
	{
		if (!g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointID])
		{
			unusedCheckpointID = checkpointID;
			break;
		}
	}

	if (unusedCheckpointID == -1)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:160("Limit of %d checkpoints reached!"), MAX_RACECHECKPOINTS);
		return COMMAND_ERROR;
	}

	GetPlayerPos(playerID, g_races[raceID][E_RACE_CHECKPOINT_POSX][unusedCheckpointID], g_races[raceID][E_RACE_CHECKPOINT_POSY][unusedCheckpointID], g_races[raceID][E_RACE_CHECKPOINT_POSZ][unusedCheckpointID]);

	SaveRaces();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:161("Checkpoint %d added to race %d (%s)"), unusedCheckpointID + 1, raceID, g_races[raceID][E_RACE_NAME]);

	return COMMAND_OK;
}