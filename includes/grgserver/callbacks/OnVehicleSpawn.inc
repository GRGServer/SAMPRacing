public OnVehicleSpawn(vehicleid)
{
	if (VehicleProperty:vehicleid[SAVEID])
	{
		mysql_query_format(false, "DELETE FROM `vehicles` WHERE `id` = %d", VehicleProperty:vehicleid[SAVEID]);
	}

	DestroyVehicle(vehicleid);
}