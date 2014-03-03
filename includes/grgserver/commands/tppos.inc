ACMD:tppos(playerID, params[], StringID:75("Teleport yourself to a specific position"))
{
	new Float:posX;
	new Float:posY;
	new Float:posZ;
	new interior;

	if (sscanf(params, "fffd", posX, posY, posZ, interior))
	{
		interior = GetPlayerInterior(playerID);
		if (sscanf(params, "fff", posX, posY, posZ))
		{
			CmdUsageMsg(playerID, "tppos", "PosX", "PosY", "PosZ", "[Interior]");
			return COMMAND_USAGE;
		}
	}

	SetPlayerPos(playerID, posX, posY, posZ);
	SetPlayerInterior(playerID, interior);
	SetCameraBehindPlayer(playerID);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:76("You teleported yourself to the position %f x %f x %f in interior %d"), posX, posY, posZ, interior);

	return COMMAND_OK;
}