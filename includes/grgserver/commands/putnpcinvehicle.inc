PCMD:putnpcinvehicle[ISADMIN](playerID, params[], StringID:190("Put a NPC in your current vehicle"))
{
	new npcPlayerID;
	if (sscanf(params, "u", npcPlayerID))
	{
		CmdUsageMsg(playerID, "putnpcinvehicle", "NPC");
		return COMMAND_USAGE;
	}

	if (npcPlayerID == INVALID_PLAYER_ID || !IsPlayerNPC(npcPlayerID))
	{
		return COMMAND_PLAYER_NOT_FOUND;
	}

	if (!IsPlayerInAnyVehicle(playerID))
	{
		return COMMAND_NOT_IN_VEHICLE;
	}

	if (GetPlayerVehicleSeat(playerID) == 0)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:191("You must not be the driver of this vehicle!"));
		return COMMAND_ERROR;
	}

	PutPlayerInVehicle(npcPlayerID, GetPlayerVehicleID(playerID), 0);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:192("The NPC is now the driver of your vehicle"));
	return COMMAND_OK;
}