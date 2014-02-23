public OnPlayerUpdate(playerid)
{
	new vehicleID = GetPlayerVehicleID(playerid);
	new vehicleSeat = GetPlayerVehicleSeat(playerid);

	// Update god mode stuff
	if (PVar:playerid[GODMODE])
	{
		SetPlayerHealth(playerid, 999999999);

		if (vehicleSeat == 0)
		{
			SetVehicleHealth(vehicleID, 999999999);
		}
	}

	// Update current area
	new areaCount = GetPlayerNumberDynamicAreas(playerid);
	if (areaCount)
	{
		new areas[MAX_AREAS];
		GetPlayerDynamicAreas(playerid, areas);
		new areaID = Streamer_GetIntData(STREAMER_TYPE_AREA, areas[0], E_STREAMER_EXTRA_ID);
		if (PVar:playerid[CURRENT_AREA] != areaID + 1)
		{
			PVar:playerid[CURRENT_AREA] = areaID + 1;
			OnPlayerEnterArea(playerid, areaID);
		}
	}
	else
	{
		if (PVar:playerid[CURRENT_AREA])
		{
			OnPlayerExitArea(playerid, PVar:playerid[CURRENT_AREA] - 1);
			PVar:playerid[CURRENT_AREA] = 0;
		}
	}

	UpdateDrifting(playerid);
}