PCMD:removevehicle[ISADMIN](playerID, params[], StringID:174("Remove the current vehicle from the database"))
{
	new vehicleID = GetPlayerVehicleID(playerID);
	if (!vehicleID)
	{
		return COMMAND_NOT_IN_VEHICLE;
	}
	if (!VehicleProperty:vehicleID[SAVEID])
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:175("This vehicle is not a saved vehicle!"));
		return COMMAND_ERROR;
	}
	MySQLFormat("DELETE FROM `vehiclecomponents` WHERE `vehicleId` = '%d'", VehicleProperty:vehicleID[SAVEID]);
	mysql_pquery(1, g_sqlQuery);
	MySQLFormat("DELETE FROM `vehicles` WHERE `id` = '%d'", VehicleProperty:vehicleID[SAVEID]);
	mysql_pquery(1, g_sqlQuery);
	MySQLFormat("DELETE FROM `originalvehicles` WHERE `id` = '%d'", VehicleProperty:vehicleID[SAVEID]);
	mysql_pquery(1, g_sqlQuery);
	VehicleProperty:vehicleID[SAVEID] = 0;
	DestroyVehicle(vehicleID);
	SendClientMessageEx(playerID, COLOR_INFO, StringID:17("The vehicle has been removed"));
	return COMMAND_OK;
}