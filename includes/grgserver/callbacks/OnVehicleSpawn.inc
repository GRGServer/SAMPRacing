public OnVehicleSpawn(vehicleid)
{
	if (VehicleProperty:vehicleid[SAVEID])
	{
		MySQLFormat("DELETE FROM `vehicles` WHERE `id` = %d", VehicleProperty:vehicleid[SAVEID]);
		mysql_pquery(1, g_sqlQuery);
	}

	DestroyVehicleEx(vehicleid);
}