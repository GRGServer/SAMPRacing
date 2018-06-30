forward OnGarageVehiclesLoaded(playerID);
public OnGarageVehiclesLoaded(playerID)
{
	new rows;
	cache_get_row_count(rows);
	if (!rows)
	{
		PVar:playerID[GARAGE_NUMBER] = -1;

		GameTextForPlayer(playerID, LanguageString(playerID, StringID:146("There are no vehicles in this garage!")), 3000, 3);

		PVar:playerID[ALLOWCMDS] = true;
		return;
	}

	new garageNumber = PVar:playerID[GARAGE_NUMBER];

	SetPlayerVirtualWorld(playerID, VIRTUALWORLD_GARAGE + playerID);

	TogglePlayerSpectating(playerID, true);

	SetPlayerCameraPosEx(playerID, g_garages[garageNumber][E_GARAGE_CAMERA_POSX], g_garages[garageNumber][E_GARAGE_CAMERA_POSY], g_garages[garageNumber][E_GARAGE_CAMERA_POSZ], g_garages[garageNumber][E_GARAGE_VEHICLE_POSX], g_garages[garageNumber][E_GARAGE_VEHICLE_POSY], g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ]);

	PVar:playerID[GARAGE_MYSQLCACHEID] = cache_save();

	CreateGarageVehicle(playerID, 0);
}