ACMD:tp(playerID, params[], StringID:50("Teleport to another player"))
{
	new targetPlayerID;
	if (sscanf(params, "u", targetPlayerID))
	{
		CmdUsageMsg(playerID, "tp", "PlayerID/Name");
		return COMMAND_USAGE;
	}

	new Float:posX;
	new Float:posY;
	new Float:posZ;
	new Float:angle;

	GetPlayerPos(targetPlayerID, posX, posY, posZ);
	GetPlayerFacingAngle(targetPlayerID, angle);

	SetPlayerPos(targetPlayerID, posX, posY, posZ);
	SetPlayerFacingAngle(targetPlayerID, angle);

	return COMMAND_OK;
}