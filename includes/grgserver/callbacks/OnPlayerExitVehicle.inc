public OnPlayerExitVehicle(playerid, vehicleid)
{
	if (DriftingState[playerid] == true)
	{
		CancelDrifting(playerid);
		SendClientMessage(playerid, 0xFFAAFFAA, "Drifting mode is OFF. You can't drift without a vehicle!");
	}
	return 1;
}