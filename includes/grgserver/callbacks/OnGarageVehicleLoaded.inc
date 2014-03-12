forward OnGarageVehicleLoaded(playerID);
public OnGarageVehicleLoaded(playerID)
{
	if (!cache_get_row_count())
	{
		PVar:playerID[GARAGE_VEHICLE_LOADING] = false;
		return;
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

	PVar:playerID[GARAGE_VEHICLE_SAVEID] = cache_get_field_content_int(0, "id");

	PVar:playerID[GARAGE_VEHICLE_ID] = CreateVehicle(cache_get_field_content_int(0, "modelId"), vehiclePosX, vehiclePosY, vehiclePosZ, vehicleAngle, cache_get_field_content_int(0, "color1"), cache_get_field_content_int(0, "color2"), -1);
	if (PVar:playerID[GARAGE_VEHICLE_ID] == INVALID_VEHICLE_ID)
	{
		PVar:playerID[GARAGE_VEHICLE_LOADING] = true;
		return;
	}

	LinkVehicleToInterior(PVar:playerID[GARAGE_VEHICLE_ID], GetPlayerInterior(playerID));
	SetVehicleVirtualWorld(PVar:playerID[GARAGE_VEHICLE_ID], GetPlayerVirtualWorld(playerID));

	SetVehicleNumberPlate(PVar:playerID[GARAGE_VEHICLE_ID], GetMySQLField("numberPlate"));
	ChangeVehiclePaintjob(PVar:playerID[GARAGE_VEHICLE_ID], cache_get_field_content_int(0, "paintjobId"));

	MySQLFormat("SELECT `componentId` FROM `vehiclecomponents` WHERE `vehicleId` = %d", PVar:playerID[GARAGE_VEHICLE_SAVEID]);
	mysql_pquery(1, g_sqlQuery, "OnGarageVehicleComponentsLoaded", "d", playerID);
}