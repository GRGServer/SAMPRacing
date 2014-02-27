public OnVehicleMod(playerid, vehicleid, componentid)
{
	if (VehicleProperty:vehicleid[SAVEID])
	{
		mysql_query_format(false, "UPDATE `vehiclecomponents` SET `componentId` = %d WHERE `vehicleId` = %d AND `slot` = %d", componentid, VehicleProperty:vehicleid[SAVEID], GetVehicleComponentType(componentid));
	}

	return true;
}