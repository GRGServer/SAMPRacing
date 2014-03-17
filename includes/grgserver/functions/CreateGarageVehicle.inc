CreateGarageVehicle(playerID, direction)
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

	new idOperator[2];
	switch (direction)
	{
		case -1:
		{
			idOperator = "<";
		}
		case 1:
		{
			idOperator = ">";
		}
		default:
		{
			idOperator = "=";
		}
	}

	MySQLFormat("SELECT `id`, `modelId`, `numberPlate`, `mileAge`, `userId`, `garageId`, `health`, `color1`, `color2`, `paintjobId` FROM `vehicles` WHERE `id` %s %d AND `userId` = %d AND `garageId` = %d ORDER BY `id` ASC LIMIT 1", idOperator, PVar:playerID[GARAGE_VEHICLE_SAVEID], PVar:playerID[USERID], g_garages[PVar:playerID[GARAGE_NUMBER]][E_GARAGE_ID]);
	mysql_pquery(1, g_sqlQuery, "OnGarageVehicleLoaded", "d", playerID);
}