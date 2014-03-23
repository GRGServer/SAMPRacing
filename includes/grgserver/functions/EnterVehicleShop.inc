EnterVehicleShop(playerID, shopID, respawnOldPos)
{
	PVar:playerID[ALLOWCMDS] = false;

	PVar:playerID[VEHICLESHOP_ID] = shopID;
	PVar:playerID[VEHICLESHOP_SPAWNOLDPOS] = respawnOldPos;

	if (!PVar:playerID[VEHICLESHOP_MODELID])
	{
		PVar:playerID[VEHICLESHOP_MODELID] = 400;
	}

	GetPlayerPos(playerID, PVar:playerID[VEHICLESHOP_OLDPOSX], PVar:playerID[VEHICLESHOP_OLDPOSY], PVar:playerID[VEHICLESHOP_OLDPOSZ]);
	GetPlayerFacingAngle(playerID, PVar:playerID[VEHICLESHOP_OLDANGLE]);
	PVar:playerID[VEHICLESHOP_OLDINTERIOR] = GetPlayerInterior(playerID);

	SetPrivateWorld(playerID, true);

	TogglePlayerSpectating(playerID, true);
	SetPlayerCameraPosEx(playerID, SHOP_VEHICLE_CAM_POSX, SHOP_VEHICLE_CAM_POSY, SHOP_VEHICLE_CAM_POSZ, SHOP_VEHICLE_VEH_POSX, SHOP_VEHICLE_VEH_POSY, SHOP_VEHICLE_VEH_POSZ);

	CreateVehicleShopVehicle(playerID);

	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO]);
	PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO]);
}