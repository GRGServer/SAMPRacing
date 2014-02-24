ExitVehicleShop(playerID)
{
	PVar:playerID[VEHICLESHOP_ISINSIDE] = false;

	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);

	SetPrivateWorld(playerID, false);

	if (PVar:playerID[VEHICLESHOP_VEHICLEID] != INVALID_VEHICLE_ID)
	{
		DestroyVehicle(PVar:playerID[VEHICLESHOP_VEHICLEID]);
	}

	PVar:playerID[SPAWNTYPE] = SPAWNTYPE_EXITVEHICLESHOP;
	TogglePlayerSpectating(playerID, false);
}