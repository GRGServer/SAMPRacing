PCMD:setgaragespawn[ISADMIN](playerID, params[], StringID:135("Set the spawn position of a garage"))
{
	new garageID;
	if (sscanf(params, "d", garageID))
	{
		CmdUsageMsg(playerID, "setgaragespawn", "GarageID");
		return COMMAND_USAGE;
	}

	new garageNumber = -1;
	new freeGarageSlot = -1;
	Foreach(index, g_garages)
	{
		if (!g_garages[index][E_GARAGE_ID])
		{
			freeGarageSlot = index;
		}

		if (g_garages[index][E_GARAGE_ID] == garageID)
		{
			garageNumber = index;
			break;
		}
	}

	if (garageNumber == -1)
	{
		if (freeGarageSlot == -1)
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:138("Limit of %d garages reached!"), MAX_GARAGES);
			return COMMAND_ERROR;
		}

		garageNumber = freeGarageSlot;

		g_garages[garageNumber][E_GARAGE_ID] = garageID;
	}

	new vehicleID = GetPlayerVehicleID(playerID);
	if (vehicleID)
	{
		GetVehiclePos(vehicleID, g_garages[garageNumber][E_GARAGE_VEHICLE_POSX], g_garages[garageNumber][E_GARAGE_VEHICLE_POSY], g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ]);
		GetVehicleZAngle(vehicleID, g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE]);
	}
	else
	{
		GetPlayerPos(playerID, g_garages[garageNumber][E_GARAGE_VEHICLE_POSX], g_garages[garageNumber][E_GARAGE_VEHICLE_POSY], g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ]);
		GetPlayerFacingAngle(playerID, g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE]);
	}

	GetPlayerCameraPos(playerID, g_garages[garageNumber][E_GARAGE_CAMERA_POSX], g_garages[garageNumber][E_GARAGE_CAMERA_POSY], g_garages[garageNumber][E_GARAGE_CAMERA_POSZ]);

	SaveGarages();

	UpdateGarage(garageNumber);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:136("The garage spawn position has been saved"));

	return COMMAND_OK;
}