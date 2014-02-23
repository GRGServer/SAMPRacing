ACMD:addtp(playerID, params[], StringID:61("Add a new teleport location"))
{
	new name[STRINGLENGTH_TELEPORTNAME];
	if (sscanf(params, "s[" #STRINGLENGTH_TELEPORTNAME "]", name))
	{
		CmdUsageMsg(playerID, "addtp", "Name");
		return COMMAND_USAGE;
	}

	Foreach(teleportID, g_teleports)
	{
		if (!StrNotNull(g_teleports[teleportID][E_TELEPORT_NAME]))
		{
			strcat(g_teleports[teleportID][E_TELEPORT_NAME], name, STRINGLENGTH_TELEPORTNAME);
			GetPlayerPos(playerID, g_teleports[teleportID][E_TELEPORT_POSX], g_teleports[teleportID][E_TELEPORT_POSY], g_teleports[teleportID][E_TELEPORT_POSZ]);
			GetPlayerFacingAngle(playerID, g_teleports[teleportID][E_TELEPORT_ANGLE]);
			g_teleports[teleportID][E_TELEPORT_INTERIOR] = GetPlayerInterior(playerID);

			SaveTeleports();

			SendClientMessageEx(playerID, COLOR_INFO, StringID:62("Teleport saved in slot %d"), teleportID);
			return COMMAND_OK;
		}
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:63("Limit of %d teleports reached!"), MAX_TELEPORTS);
	return COMMAND_ERROR;
}