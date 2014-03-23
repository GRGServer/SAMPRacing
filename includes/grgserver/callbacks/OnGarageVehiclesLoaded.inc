forward OnGarageVehiclesLoaded(playerID);
public OnGarageVehiclesLoaded(playerID)
{
	if (!cache_get_row_count())
	{
		PVar:playerID[GARAGE_NUMBER] = -1;

		GameTextForPlayer(playerID, LanguageString(playerID, StringID:146("There are no vehicles in this garage!")), 3000, 3);

		PVar:playerID[ALLOWCMDS] = true;
		return;
	}

	// Save the old position to restore on garage exit
	GetPlayerPos(playerID, PVar:playerID[GARAGE_OLDPOSX], PVar:playerID[GARAGE_OLDPOSY], PVar:playerID[GARAGE_OLDPOSZ]);
	GetPlayerFacingAngle(playerID, PVar:playerID[GARAGE_OLDANGLE]);
	PVar:playerID[GARAGE_OLDINTERIOR] = GetPlayerInterior(playerID);

	SetPrivateWorld(playerID, true);

	TogglePlayerSpectating(playerID, true);

	new Float:cameraPosX;
	new Float:cameraPosY;
	new Float:cameraPosZ;
	new Float:vehiclePosX;
	new Float:vehiclePosY;
	new Float:vehiclePosZ;
	new interior;

	switch (g_garages[PVar:playerID[GARAGE_NUMBER]][E_GARAGE_TYPE])
	{
		case GARAGE_LARGE:
		{
			cameraPosX = GARAGE_LARGE_CAMERA_POSX;
			cameraPosY = GARAGE_LARGE_CAMERA_POSY;
			cameraPosZ = GARAGE_LARGE_CAMERA_POSZ;

			vehiclePosX = GARAGE_LARGE_VEHICLE_POSX;
			vehiclePosY = GARAGE_LARGE_VEHICLE_POSY;
			vehiclePosZ = GARAGE_LARGE_VEHICLE_POSZ;

			interior = GARAGE_LARGE_INTERIOR;
		}
		case GARAGE_SMALL:
		{
			cameraPosX = GARAGE_SMALL_CAMERA_POSX;
			cameraPosY = GARAGE_SMALL_CAMERA_POSY;
			cameraPosZ = GARAGE_SMALL_CAMERA_POSZ;

			vehiclePosX = GARAGE_SMALL_VEHICLE_POSX;
			vehiclePosY = GARAGE_SMALL_VEHICLE_POSY;
			vehiclePosZ = GARAGE_SMALL_VEHICLE_POSZ;

			interior = GARAGE_SMALL_INTERIOR;
		}
	}

	SetPlayerInterior(playerID, interior);
	SetPlayerCameraPosEx(playerID, cameraPosX, cameraPosY, cameraPosZ, vehiclePosX, vehiclePosY, vehiclePosZ);

	PVar:playerID[GARAGE_MYSQLCACHEID] = cache_save();

	CreateGarageVehicle(playerID, 0);
}