ACMD:tpto(playerID, params[], StringID:50("Teleport yourself to another player"))
{
	new targetPlayerID;
	if (sscanf(params, "u", targetPlayerID))
	{
		CmdUsageMsg(playerID, "tpto", "PlayerID/Name");
		return COMMAND_USAGE;
	}

	if (targetPlayerID == INVALID_PLAYER_ID)
	{
		return COMMAND_PLAYER_NOT_FOUND;
	}

	new Float:posX;
	new Float:posY;
	new Float:posZ;
	new Float:angle;

	GetPlayerPos(targetPlayerID, posX, posY, posZ);
	GetPlayerFacingAngle(targetPlayerID, angle);

	SetPlayerPos(playerID, posX, posY, posZ);
	SetPlayerFacingAngle(playerID, angle);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:17("You teleported yourself to %u"), targetPlayerID);

	return COMMAND_OK;
}