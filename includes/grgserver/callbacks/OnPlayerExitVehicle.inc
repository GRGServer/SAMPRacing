public OnPlayerExitVehicle(playerid, vehicleid)
{
	SaveVehicle(vehicleid);

	// The player is in a race which has been started
	if (PVar:playerid[RACE_ID] != -1 && PVar:playerid[RACE_STARTED])
	{
		if (PVar:playerid[RACE_VEHICLEID] == vehicleid)
		{
			PVar:playerid[RACE_DISQUALIFY_TIMEOUT] = RACE_DISQUALIFICATION_TIMEOUT;
			PVar:playerid[RACE_DISQUALIFY_TIMER] = SetTimerEx("Timer_DisqualifyRacePlayer", 1000, true, "d", playerid);
		}
	}
}