public OnPlayerSpawn(playerid)
{
	switch (PVar:playerid[SPAWN_TYPE])
	{
		case SPAWNTYPE_BUYVEHICLESHOP:// Spawned after buying a vehicle from vehicle shop
		{
			new vehicleID = PVar:playerid[VEHICLESHOP_VEHICLEID];

			VehicleProperty:vehicleID[USERID] = PVar:playerid[USERID];

			SetPlayerInterior(playerid, PVar:playerid[SPAWN_INTERIOR]);

			SetVehiclePos(vehicleID, PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);
			SetVehicleZAngle(vehicleID, PVar:playerid[SPAWN_ANGLE]);

			LinkVehicleToInterior(vehicleID, GetPlayerInterior(playerid));
			SetVehicleVirtualWorld(vehicleID, GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, vehicleID, 0);

			SaveVehicle(vehicleID, true);

			GivePlayerMoney(playerid, -g_vehicleModels[PVar:playerid[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE]);

			PlayAudioFileForPlayer(playerid, AUDIOFILE_VEHICLEBOUGHT);
			GameTextForPlayer(playerid, LanguageString(playerid, StringID:85("Vehicle bought")), 5000, 1);

			PVar:playerid[VEHICLESHOP_ID] = -1;
			PVar:playerid[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;
		}
		default:
		{
			new Float:posX = PVar:playerid[SPAWN_POSX];
			new Float:posY = PVar:playerid[SPAWN_POSY];
			new Float:posZ = PVar:playerid[SPAWN_POSZ];
			new Float:angle = PVar:playerid[SPAWN_ANGLE];
			new interior = PVar:playerid[SPAWN_INTERIOR];

			// Specified position of the player is 0 x 0 x 0 which means the spawn location has not been set (e.g. first spawn or unexcpected respawn)
			if (!posX && !posY && !posZ)
			{
				posX = SPAWN_POSX;
				posY = SPAWN_POSY;
				posZ = SPAWN_POSZ;
				angle = SPAWN_ANGLE;
				interior = SPAWN_INTERIOR;
			}

			SetPlayerPos(playerid, posX, posY, posZ);
			SetPlayerFacingAngle(playerid, angle);
			SetPlayerInterior(playerid, interior);

			SetCameraBehindPlayer(playerid);
		}
	}

	// Reset spawn values
	PVar:playerid[SPAWN_TYPE] = SPAWNTYPE_DEFAULT;
	PVar:playerid[SPAWN_POSX] = 0;
	PVar:playerid[SPAWN_POSY] = 0;
	PVar:playerid[SPAWN_POSZ] = 0;
	PVar:playerid[SPAWN_ANGLE] = 0;
	PVar:playerid[SPAWN_INTERIOR] = 0;

	return true;
}