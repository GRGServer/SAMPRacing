public OnPlayerSpawn(playerid)
{
	new spawnType = PVar:playerid[SPAWNTYPE];
	PVar:playerid[SPAWNTYPE] = SPAWNTYPE_DEFAULT;

	switch (spawnType)
	{
		case SPAWNTYPE_BUYVEHICLESHOP:// Spawned after buying a vehicle from vehicle shop
		{
			new vehicleShopID = PVar:playerid[VEHICLESHOP_ID];
			new vehicleID = PVar:playerid[VEHICLESHOP_VEHICLEID];

			VehicleProperty:vehicleID[USERID] = PVar:playerid[USERID];

			if (PVar:playerid[VEHICLESHOP_SPAWNOLDPOS])
			{
				SetVehiclePos(vehicleID, PVar:playerid[VEHICLESHOP_OLDPOSX], PVar:playerid[VEHICLESHOP_OLDPOSY], PVar:playerid[VEHICLESHOP_OLDPOSZ]);
				SetVehicleZAngle(vehicleID, PVar:playerid[VEHICLESHOP_OLDANGLE]);
			}
			else
			{
				SetVehiclePos(vehicleID, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSX], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSY], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSZ]);
				SetVehicleZAngle(vehicleID, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_ANGLE]);
			}

			SetVehicleVirtualWorld(vehicleID, GetPlayerVirtualWorld(playerid));
			PutPlayerInVehicle(playerid, vehicleID, 0);

			VehicleProperty:vehicleID[USERID] = PVar:playerid[USERID];
			SaveVehicle(vehicleID, true);

			GivePlayerMoney(playerid, -g_vehicleModels[PVar:playerid[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE]);

			PlayAudioFileForPlayer(playerid, AUDIOFILE_VEHICLEBOUGHT);
			GameTextForPlayer(playerid, LanguageString(playerid, StringID:85("Vehicle bought")), 5000, 1);

			PVar:playerid[VEHICLESHOP_ID] = -1;
			PVar:playerid[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;
		}
		case SPAWNTYPE_DEATH:// Spawned after death
		{
			new pickupID = GetClosestPickup(PVar:playerid[DEATH_POSX], PVar:playerid[DEATH_POSY], PVar:playerid[DEATH_POSZ], PICKUPTYPE_HOSPITAL);

			SetPlayerPos(playerid, g_pickups[pickupID][E_PICKUP_POSX], g_pickups[pickupID][E_PICKUP_POSY], g_pickups[pickupID][E_PICKUP_POSZ]);
		}
		case SPAWNTYPE_EXITVEHICLESHOP:// Spawned after exit of vehicle shop
		{
			new vehicleShopID = PVar:playerid[VEHICLESHOP_ID];

			if (PVar:playerid[VEHICLESHOP_SPAWNOLDPOS])
			{
				SetPlayerPos(playerid, PVar:playerid[VEHICLESHOP_OLDPOSX], PVar:playerid[VEHICLESHOP_OLDPOSY], PVar:playerid[VEHICLESHOP_OLDPOSZ]);
				SetPlayerFacingAngle(playerid, PVar:playerid[VEHICLESHOP_OLDANGLE]);
			}
			else
			{
				SetPlayerPos(playerid, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSX], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSY], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSZ]);
				SetPlayerFacingAngle(playerid, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_ANGLE]);
			}

			SetCameraBehindPlayer(playerid);

			PVar:playerid[VEHICLESHOP_ID] = -1;
			PVar:playerid[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;
		}
		case SPAWNTYPE_FIRSTSPAWN:// Spawned after login/register
		{
			new Cache:result = mysql_query_format(true, "SELECT `posX`, `posY`, `posZ`, `angle`, `interior` FROM `users` WHERE `id` = %d", PVar:playerid[USERID]);
			new Float:posX = cache_get_field_content_float(0, "posX");
			new Float:posY = cache_get_field_content_float(0, "posY");
			new Float:posZ = cache_get_field_content_float(0, "posZ");
			new Float:angle = cache_get_field_content_float(0, "angle");
			new interior = cache_get_field_content_int(0, "interior");
			cache_delete(result);

			// Last position of player is 0 x 0 x 0 which means the player was never spawned -> Spawn at configured default location
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
		}
		default:
		{
			SetPlayerPos(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
			SetPlayerFacingAngle(playerid, SPAWN_ANGLE);
			SetPlayerInterior(playerid, SPAWN_INTERIOR);
		}
	}

	return true;
}