forward cmd_npccmd(playerID, params[]);
public cmd_npccmd(playerID, params[])
{
	// The command is only available for NPCs (As communication channel)
	if (!IsPlayerNPC(playerID))
	{
		return COMMAND_NOT_FOUND;
	}

	new command[100];
	new parameters[200];
	if (sscanf(params, "ss", command, parameters))
	{
		if (sscanf(params, "s", command))
		{
			return COMMAND_ERROR;
		}
	}

	if (IsStr(command, NPCCMD_LOG))
	{
		printf("[NPC Log: %s] %s", GetPlayerNameEx(playerID), parameters);
		return COMMAND_OK;
	}

	if (IsStr(command, NPCCMD_RECORDINGENDED))
	{
		// Recording has ended
		return COMMAND_OK;
	}

	return COMMAND_ERROR;
}