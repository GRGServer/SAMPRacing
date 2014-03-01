ACMD:maptp(playerID, params[], StringID:120("Teleport yourself to the target selected on the map"))
{
	if (PVar:playerID[MAP_POSX] && PVar:playerID[MAP_POSY])
	{
		SetPlayerPosFindZ(playerID, PVar:playerID[MAP_POSX], PVar:playerID[MAP_POSY], 6000.0);
		SetTimerEx("Timer_SetPlayerPosFindZ", 500, false, "dfff", playerID, PVar:playerID[MAP_POSX], PVar:playerID[MAP_POSY], 6000.0);// Workaround for http://forum.sa-mp.com/showthread.php?p=1800073
		SendClientMessageEx(playerID, COLOR_INFO, StringID:121("You got teleported to the target on your map"));

		return COMMAND_OK;
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:122("You have not selected the target on your map!"));
	}

	return COMMAND_ERROR;
}