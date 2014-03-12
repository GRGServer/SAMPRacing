EnterGarage(playerID, garageNumber)
{
	SetPrivateWorld(playerID, true);

	TogglePlayerSpectating(playerID, true);

	PVar:playerID[GARAGE_NUMBER] = garageNumber;

	new Float:cameraPosX;
	new Float:cameraPosY;
	new Float:cameraPosZ;
	new Float:vehiclePosX;
	new Float:vehiclePosY;
	new Float:vehiclePosZ;
	new interior;

	switch (g_garages[garageNumber][E_GARAGE_TYPE])
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

	CreateGarageVehicle(playerID, 1);
}