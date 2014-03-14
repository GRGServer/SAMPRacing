LockVehicle(vehicleID, lockState, playerID = INVALID_PLAYER_ID)
{
	new engine;
	new lights;
	new alarm;
	new doors;
	new bonnet;
	new boot;
	new objective;

	GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);

	// Already locked or unlocked
	if (doors == lockState)
	{
		return;
	}

	SetVehicleParamsEx(vehicleID, engine, lights, alarm, lockState, bonnet, boot, objective);

	if (playerID != INVALID_PLAYER_ID)
	{
		SetVehicleParamsForPlayer(vehicleID, playerID, objective, false);// Always allow the executing player to enter the vehicle

		if (doors)
		{
			PlaySound(playerID, SOUND_VEHICLE_LOCK);
			SendClientMessageEx(playerID, COLOR_INFO, StringID:148("The doors of your vehicle have been locked"));
		}
		else
		{
			PlaySound(playerID, SOUND_VEHICLE_UNLOCK);
			SendClientMessageEx(playerID, COLOR_INFO, StringID:149("The doors of your vehicle have been unlocked"));
		}
	}
}