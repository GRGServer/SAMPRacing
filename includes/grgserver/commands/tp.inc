CMD:tp(playerID, params[], stringID:-1("Teleport yourself to a predefined location"))
{
	new name[STRINGLENGTH_TELEPORTNAME];
	if (sscanf(params, "s[" #STRINGLENGTH_TELEPORTNAME "]", name))
	{
		CmdUsageMsg(playerID, "tp", "Name");
		return COMMAND_USAGE;
	}

	Foreach(teleportID, g_teleports)
	{
		// Check whether the teleport is the requested one
		if (StrNotNull(g_teleports[teleportID][E_TELEPORT_NAME]) && !strcmp(g_teleports[teleportID][E_TELEPORT_NAME], name, true))
		{
			// Check whether the teleport is not only for admins or the player is an admin
			if (!g_teleports[teleportID][E_TELEPORT_ADMINSONLY] || PVar:playerID[ISADMIN])
			{
				TeleportTo(playerID, teleportID);
				return COMMAND_OK;
			}
			else
			{
				return COMMAND_PERMISSION_DENIED;
			}
		}
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:49("Teleport not found!"));

	return COMMAND_ERROR;
}