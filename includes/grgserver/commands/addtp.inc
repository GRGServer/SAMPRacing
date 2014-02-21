ACMD:addtp(playerID, params[], StringID:61("Add a new teleport location"))
{
	new name[STRINGLENGTH_TELEPORTNAME];
	if (sscanf(params, "s[" #STRINGLENGTH_TELEPORTNAME "]", name))
	{
		CmdUsageMsg(playerID, "addtp", "Name");
		return COMMAND_USAGE;
	}

	Foreach(teleportID, teleports)
	{
		if (!StrNotNull(teleports[teleportID][TELEPORT_NAME]))
		{
			strcat(teleports[teleportID][TELEPORT_NAME], name, STRINGLENGTH_TELEPORTNAME);
			GetPlayerPos(playerID, teleports[teleportID][TELEPORT_POSX], teleports[teleportID][TELEPORT_POSY], teleports[teleportID][TELEPORT_POSZ]);
			GetPlayerFacingAngle(playerID, teleports[teleportID][TELEPORT_ANGLE]);
			teleports[teleportID][TELEPORT_INTERIOR] = GetPlayerInterior(playerID);

			SaveTeleports();

			SendClientMessageEx(playerID, COLOR_INFO, StringID:62("Teleport saved in slot %d"), teleportID);
			return COMMAND_OK;
		}
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:63("Limit of %d teleports reached!"), MAX_TELEPORTS);
	return COMMAND_ERROR;
}