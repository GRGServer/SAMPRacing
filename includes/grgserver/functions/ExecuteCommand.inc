ExecuteCommand(playerID, command[], parameters[], isSubCall = false)
{
	FormatNew:functionName[MAX_FUNCTION_NAME]("cmd_%s", command);

	new returnCode = COMMAND_NOT_FOUND;
	new foundCommand;

	// Check whether the function exists
	if (funcidx(functionName) != -1)
	{
		if (StrNotNull(parameters))
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, parameters);
		}
		else
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, "\1");
		}
		foundCommand = true;
	}

	if (!foundCommand)
	{
		// Search aliases for the command
		Foreach(aliasID, g_commandAliases)
		{
			if (StrNotNull(g_commandAliases[aliasID][E_COMMANDALIAS_NAME]) && !strcmp(g_commandAliases[aliasID][E_COMMANDALIAS_NAME], command, true))
			{
				new fullParameters[256];
				strcat(fullParameters, g_commandAliases[aliasID][E_COMMANDALIAS_PARAMETERS]);
				if (strlen(g_commandAliases[aliasID][E_COMMANDALIAS_PARAMETERS]) && strlen(parameters))
				{
					strcat(fullParameters, " ");
				}
				strcat(fullParameters, parameters);

				returnCode = ExecuteCommand(playerID, g_commandAliases[aliasID][E_COMMANDALIAS_COMMAND], fullParameters, true);
				foundCommand = true;
				break;
			}
		}
	}

	if (!foundCommand)
	{
		// Search teleports for the command
		Foreach(teleportID, g_teleports)
		{
			// Check whether the teleport command is the requested command
			if (StrNotNull(g_teleports[teleportID][E_TELEPORT_COMMAND]) && !strcmp(g_teleports[teleportID][E_TELEPORT_COMMAND], command, true))
			{
				// Check whether the teleport is not only for admins or the player is an admin
				if (!g_teleports[teleportID][E_TELEPORT_ADMINSONLY] || PVar:playerID[ISADMIN])
				{
					TeleportTo(playerID, teleportID);
					returnCode = COMMAND_OK;
				}
				else
				{
					returnCode = COMMAND_PERMISSION_DENIED;
				}
				foundCommand = true;
				break;
			}
		}
	}

	if (isSubCall)
	{
		return returnCode;
	}

	return OnPlayerCommandPerformed(playerID, command, parameters, returnCode);
}