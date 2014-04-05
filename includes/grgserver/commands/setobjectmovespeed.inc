PCMD:setobjectmovespeed[ISADMIN](playerID, params[], StringID:214("Set the move speed of the currently selected object"))
{
	new objectID = PVar:playerID[OBJEDITOR_ID];
	if (!objectID)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:216("No object selected!"));
		return COMMAND_ERROR;
	}

	new Float:speed;
	if (sscanf(params, "f", speed))
	{
		CmdUsageMsg(playerID, "setobjectmovespeed", "Speed");
		return COMMAND_USAGE;
	}

	Object:objectID[MOVE_SPEED] = speed;

	SaveObjects(Object:objectID[FILENAME]);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:215("The object move speed has been changed"));
	return COMMAND_OK;
}