EnterVehicleShop(playerID)
{
	PVar:playerID[VEHICLESHOP_ISINSIDE] = true;

	if (!PVar:playerID[VEHICLESHOP_MODELID])
	{
		PVar:playerID[VEHICLESHOP_MODELID] = 400;
	}

	SetPrivateWorld(playerID, true);

	TogglePlayerSpectating(playerID, true);
	SetPlayerCameraPosEx(playerID, SHOP_VEHICLE_CAM_POSX, SHOP_VEHICLE_CAM_POSY, SHOP_VEHICLE_CAM_POSZ, SHOP_VEHICLE_VEH_POSX, SHOP_VEHICLE_VEH_POSY, SHOP_VEHICLE_VEH_POSZ);

	CreateVehicleShopVehicle(playerID);

	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);
}