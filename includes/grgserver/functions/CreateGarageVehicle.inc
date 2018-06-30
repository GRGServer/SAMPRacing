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

	cache_set_active(PVar:playerID[GARAGE_MYSQLCACHEID]);

	PVar:playerID[GARAGE_ROW] = row;

	cache_get_value_int(row, "id", PVar:playerID[GARAGE_VEHICLE_SAVEID]);

	PVar:playerID[GARAGE_VEHICLE_ID] = LoadVehicle(row, g_garages[garageNumber][E_GARAGE_VEHICLE_POSX], g_garages[garageNumber][E_GARAGE_VEHICLE_POSY], g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ], g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE]);
	if (PVar:playerID[GARAGE_VEHICLE_ID] == INVALID_VEHICLE_ID)
	{
		PVar:playerID[GARAGE_VEHICLE_LOADING] = false;
		return;
	}

	LinkVehicleToInterior(PVar:playerID[GARAGE_VEHICLE_ID], GetPlayerInterior(playerID));
	SetVehicleVirtualWorld(PVar:playerID[GARAGE_VEHICLE_ID], VIRTUALWORLD_GARAGE + playerID);

	new rows;
	cache_get_row_count(rows);
	FormatNew:string[256]("%s~n~%d / %d", g_vehicleModels[GetVehicleModel(PVar:playerID[GARAGE_VEHICLE_ID]) - 400][E_VEHICLEMODEL_NAME], row + 1, rows);
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO], string);

	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_CTRL_INFO]);
	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO]);

	MySQLFormat("SELECT `componentId` FROM `vehiclecomponents` WHERE `vehicleId` = %d", PVar:playerID[GARAGE_VEHICLE_SAVEID]);
	mysql_pquery(1, g_sqlQuery, "OnGarageVehicleComponentsLoaded", "d", playerID);
}