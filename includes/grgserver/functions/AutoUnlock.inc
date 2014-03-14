LAutoUnlock(vehicleid)
{
	for(new v = 0; v <L_VEHICLE; v++)
	{
		SetVehicleParamsForPlayer(vehicleid,v, 0, 0);
	}
	VehicleStatus[vehicleid] = 0;
}