public OnPlayerExitVehicle(playerid, vehicleid)
{
	if (PVar:playerid[DRIFTING_STATE])
	{
		StopDrifting(playerid);
	}
}