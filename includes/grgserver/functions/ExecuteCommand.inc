ExecuteCommand(playerID, command[], parameters[])
{
	FormatNew:functionName[MAX_FUNCTION_NAME]("cmd_%s", command);

	new returnCode = COMMAND_NOT_FOUND;

	// Check whether the function exists
	if (funcidx(functionName) == -1)
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
				break;
			}
		}
	}
	else
	{
		if (StrNotNull(parameters))
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, parameters);
		}
		else
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, "\1");
		}
	}
	return OnPlayerCommandPerformed(playerID, command, parameters, returnCode);
}