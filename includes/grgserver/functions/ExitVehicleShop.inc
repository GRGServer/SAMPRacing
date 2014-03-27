ExitVehicleShop(playerID, buy)
{
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);

	SetPlayerVirtualWorld(playerID, 0);

	new vehicleShopID = PVar:playerID[VEHICLESHOP_ID];

	new spawnType = buy ? SPAWNTYPE_BUYVEHICLESHOP : SPAWNTYPE_DEFAULT;

	if (PVar:playerID[VEHICLESHOP_SPAWNOLDPOS])
	{
		SetPlayerSpawn(playerID, spawnType, PVar:playerID[VEHICLESHOP_OLDPOSX], PVar:playerID[VEHICLESHOP_OLDPOSY], PVar:playerID[VEHICLESHOP_OLDPOSZ], PVar:playerID[VEHICLESHOP_OLDANGLE], PVar:playerID[VEHICLESHOP_OLDINTERIOR]);
	}
	else
	{
		if (buy)
		{
			SetPlayerSpawn(playerID, spawnType, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSX], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSY], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_POSZ], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_BUYSPAWN_ANGLE]);
		}
		else
		{
			SetPlayerSpawn(playerID, spawnType, g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSX], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSY], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_POSZ], g_vehicleShops[vehicleShopID][E_VEHICLESHOP_QUITSPAWN_ANGLE]);
		}
	}

	if (!buy)
	{
		DestroyVehicleEx(PVar:playerID[VEHICLESHOP_VEHICLEID]);

		PVar:playerID[VEHICLESHOP_ID] = -1;
		PVar:playerID[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;
	}

	TogglePlayerSpectating(playerID, false);

	PVar:playerID[ALLOWCMDS] = true;
}