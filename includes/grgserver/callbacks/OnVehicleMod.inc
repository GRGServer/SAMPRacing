public OnVehicleMod(playerid, vehicleid, componentid)
{
	if (VehicleProperty:vehicleid[SAVEID])
	{
		MySQLFormat("UPDATE `vehiclecomponents` SET `componentId` = %d WHERE `vehicleId` = %d AND `slot` = %d", componentid, VehicleProperty:vehicleid[SAVEID], GetVehicleComponentType(componentid));
		mysql_pquery(1, g_sqlQuery);
	}

	return true;
}