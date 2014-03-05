public OnPlayerUpdate(playerid)
{
	if (IsPlayerNPC(playerid))
	{
		return true;
	}

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
			// Exit the old area
			if (PVar:playerid[CURRENT_AREA])
			{
				OnPlayerExitArea(playerid, PVar:playerid[CURRENT_AREA] - 1);
			}

			// Enter the area
			PVar:playerid[CURRENT_AREA] = areaID + 1;
			OnPlayerEnterArea(playerid, areaID);
		}
	}
	else
	{
		// Exit the area
		if (PVar:playerid[CURRENT_AREA])
		{
			OnPlayerExitArea(playerid, PVar:playerid[CURRENT_AREA] - 1);
			PVar:playerid[CURRENT_AREA] = 0;
		}
	}

	UpdateDrifting(playerid);

	if (PVar:playerid[SETCAMERA_COUNT] > 0)
	{
		PVar:playerid[SETCAMERA_COUNT]--;
		SetPlayerCameraPos(playerid, PVar:playerid[SETCAMERA_POSX], PVar:playerid[SETCAMERA_POSY], PVar:playerid[SETCAMERA_POSZ]);
		SetPlayerCameraLookAt(playerid, PVar:playerid[SETCAMERA_LOOKATX], PVar:playerid[SETCAMERA_LOOKATY], PVar:playerid[SETCAMERA_LOOKATZ]);
	}

	return true;
}