ExitGarage(playerID, withVehicle)
{
	// Prevent exit while loading the vehicle
	if (PVar:playerID[GARAGE_VEHICLE_LOADING])
	{
		return;
	}

	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_CTRL_INFO]);
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO]);

	SetPlayerVirtualWorld(playerID, 0);

	new spawnType = withVehicle ? SPAWNTYPE_GETGARAGEVEHICLE : SPAWNTYPE_DEFAULT;

	SetPlayerSpawn(playerID, spawnType, PVar:playerID[GARAGE_OLDPOSX], PVar:playerID[GARAGE_OLDPOSY], PVar:playerID[GARAGE_OLDPOSZ], PVar:playerID[GARAGE_OLDANGLE], PVar:playerID[GARAGE_OLDINTERIOR]);

	if (!withVehicle)
	{
		DestroyVehicleEx(PVar:playerID[GARAGE_VEHICLE_ID]);

		PVar:playerID[GARAGE_NUMBER] = -1;
		PVar:playerID[GARAGE_VEHICLE_ID] = INVALID_VEHICLE_ID;
	}

	TogglePlayerSpectating(playerID, false);

	PVar:playerID[ALLOWCMDS] = true;
}