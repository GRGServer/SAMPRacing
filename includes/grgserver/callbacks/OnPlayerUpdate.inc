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

	if (PVar:playerid[SETCAMERA_COUNT] > 0)
	{
		PVar:playerid[SETCAMERA_COUNT]--;
		SetPlayerCameraPos(playerid, PVar:playerid[SETCAMERA_POSX], PVar:playerid[SETCAMERA_POSY], PVar:playerid[SETCAMERA_POSZ]);
		SetPlayerCameraLookAt(playerid, PVar:playerid[SETCAMERA_LOOKATX], PVar:playerid[SETCAMERA_LOOKATY], PVar:playerid[SETCAMERA_LOOKATZ]);
	}

	if (PVar:playerid[SHOWPOS])
	{
		new Float:posX;
		new Float:posY;
		new Float:posZ;
		GetPlayerPos(playerid, posX, posY, posZ);
		FormatNew:showPosString[100]("X: %f~n~Y: %f~n~Z: %f", posX, posY, posZ);
		PlayerTextDrawSetString(playerid, g_playerTextDraws[playerid][E_PTD_SHOWPOS], showPosString);
	}

	return true;
}