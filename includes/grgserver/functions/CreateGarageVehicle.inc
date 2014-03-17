CreateGarageVehicle(playerID, row)
{
	// Prevent loading multiple times
	if (PVar:playerID[GARAGE_VEHICLE_LOADING])
	{
		return;
	}

	PVar:playerID[GARAGE_VEHICLE_LOADING] = true;

	if (PVar:playerID[GARAGE_VEHICLE_ID] != INVALID_VEHICLE_ID)
	{
		DestroyVehicleEx(PVar:playerID[GARAGE_VEHICLE_ID]);
	}

	new garageNumber = PVar:playerID[GARAGE_NUMBER];

	new Float:vehiclePosX;
	new Float:vehiclePosY;
	new Float:vehiclePosZ;
	new Float:vehicleAngle;

	switch (g_garages[garageNumber][E_GARAGE_TYPE])
	{
		case GARAGE_LARGE:
		{
			vehiclePosX = GARAGE_LARGE_VEHICLE_POSX;
			vehiclePosY = GARAGE_LARGE_VEHICLE_POSY;
			vehiclePosZ = GARAGE_LARGE_VEHICLE_POSZ;
			vehicleAngle = GARAGE_LARGE_VEHICLE_ANGLE;
		}
		case GARAGE_SMALL:
		{
			vehiclePosX = GARAGE_SMALL_VEHICLE_POSX;
			vehiclePosY = GARAGE_SMALL_VEHICLE_POSY;
			vehiclePosZ = GARAGE_SMALL_VEHICLE_POSZ;
			vehicleAngle = GARAGE_SMALL_VEHICLE_ANGLE;
		}
	}

	cache_set_active(PVar:playerID[GARAGE_MYSQLCACHEID]);

	PVar:playerID[GARAGE_ROW] = row;

	PVar:playerID[GARAGE_VEHICLE_SAVEID] = cache_get_field_content_int(row, "id");

	PVar:playerID[GARAGE_VEHICLE_ID] = LoadVehicle(row, vehiclePosX, vehiclePosY, vehiclePosZ, vehicleAngle);
	if (PVar:playerID[GARAGE_VEHICLE_ID] == INVALID_VEHICLE_ID)
	{
		PVar:playerID[GARAGE_VEHICLE_LOADING] = false;
		return;
	}

	LinkVehicleToInterior(PVar:playerID[GARAGE_VEHICLE_ID], GetPlayerInterior(playerID));
	SetVehicleVirtualWorld(PVar:playerID[GARAGE_VEHICLE_ID], GetPlayerVirtualWorld(playerID));

	FormatNew:string[256]("%s~n~%d / %d", g_vehicleModels[GetVehicleModel(PVar:playerID[GARAGE_VEHICLE_ID]) - 400][E_VEHICLEMODEL_NAME], row + 1, cache_get_row_count());
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO], string);

	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_CTRL_INFO]);
	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO]);

	MySQLFormat("SELECT `componentId` FROM `vehiclecomponents` WHERE `vehicleId` = %d", PVar:playerID[GARAGE_VEHICLE_SAVEID]);
	mysql_pquery(1, g_sqlQuery, "OnGarageVehicleComponentsLoaded", "d", playerID);
}