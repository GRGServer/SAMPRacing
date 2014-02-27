ExitVehicleShop(playerID, buy)
{
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);

	SetPrivateWorld(playerID, false);

	if (buy)
	{
		PVar:playerID[SPAWNTYPE] = SPAWNTYPE_BUYVEHICLESHOP;
	}
	else
	{
		DestroyVehicle(PVar:playerID[VEHICLESHOP_VEHICLEID]);
		PVar:playerID[SPAWNTYPE] = SPAWNTYPE_EXITVEHICLESHOP;
	}

	TogglePlayerSpectating(playerID, false);
}