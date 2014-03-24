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

	DeleteVehicle(vehicleID);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:176("The vehicle has been removed"));
	return COMMAND_OK;
}