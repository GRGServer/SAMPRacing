CMD:lock(playerID, params[], StringID:147("Lock or unlock your Vehicle"))
{
	if (IsPlayerInAnyVehicle(playerID))
	{
		return COMMAND_NOT_IN_VEHICLE;
	}

	if (GetPlayerVehicleSeat(playerID))
	{
		return COMMAND_NOT_VEHICLE_DRIVER;
	}

	new vehicleID = GetPlayerVehicleID(playerID);

	new engine;
	new lights;
	new alarm;
	new doors;
	new bonnet;
	new boot;
	new objective;

	GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);

	LockVehicle(vehicleID, !doors, playerID);

	return COMMAND_OK;
}