EnterVehicleShop(playerID)
{
	PVar:playerID[VEHICLESHOP_ISINSIDE] = true;

	if (!PVar:playerID[VEHICLESHOP_MODELID])
	{
		PVar:playerID[VEHICLESHOP_MODELID] = 400;
	}

	SetPrivateWorld(playerID, true);

	TogglePlayerSpectating(playerID, true);

	CreateVehicleShopVehicle(playerID);

	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);

	SetTimerEx("Timer_EnterVehicleShopSpawn", 10, false, "d", playerID);
}