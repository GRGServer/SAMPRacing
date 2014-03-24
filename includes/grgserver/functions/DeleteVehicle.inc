DeleteVehicle(vehicleID)
{
	if (VehicleProperty:vehicleID[SAVEID])
	{
		MySQLFormat("DELETE FROM `vehicles` WHERE `id` = %d", VehicleProperty:vehicleID[SAVEID]);
		mysql_pquery(1, g_sqlQuery);
	}

	DestroyVehicleEx(vehicleID);
}