PCMD:settuninggaragespawn[ISADMIN](playerID, params[], StringID:237("Set the spawn position of a tuning garage"))
{
	new tuningGarageID;
	if (sscanf(params, "d", tuningGarageID))
	{
		CmdUsageMsg(playerID, "settuninggaragespawn", "TuningGarageID");
		return COMMAND_USAGE;
	}

	new tuningGarageNumber = -1;
	new freeGarageSlot = -1;
	Foreach(index, g_tuningGarages)
	{
		if (!g_tuningGarages[index][E_TUNINGGARAGE_ID])
		{
			freeGarageSlot = index;
		}

		if (g_tuningGarages[index][E_TUNINGGARAGE_ID] == tuningGarageID)
		{
			tuningGarageNumber = index;
			break;
		}
	}

	if (tuningGarageNumber == -1)
	{
		if (freeGarageSlot == -1)
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:240("Limit of %d tuning garages reached!"), MAX_TUNINGGARAGES);
			return COMMAND_ERROR;
		}

		tuningGarageNumber = freeGarageSlot;

		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ID] = tuningGarageID;
	}

	new vehicleID = GetPlayerVehicleID(playerID);
	if (vehicleID)
	{
		GetVehiclePos(vehicleID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ]);
		GetVehicleZAngle(vehicleID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_ANGLE]);
	}
	else
	{
		GetPlayerPos(playerID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ]);
		GetPlayerFacingAngle(playerID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_ANGLE]);
	}

	GetPlayerCameraPos(playerID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSZ]);

	SaveTuningGarages();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:241("The tuning garage spawn position has been saved"));

	return COMMAND_OK;
}