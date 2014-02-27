CreateVehicleShopVehicle(playerID)
{
	if (PVar:playerID[VEHICLESHOP_VEHICLEID] != INVALID_VEHICLE_ID)
	{
		DestroyVehicle(PVar:playerID[VEHICLESHOP_VEHICLEID]);
	}

	new modelID = PVar:playerID[VEHICLESHOP_MODELID];

	PVar:playerID[VEHICLESHOP_VEHICLEID] = CreateVehicle(modelID, SHOP_VEHICLE_VEH_POSX, SHOP_VEHICLE_VEH_POSY, SHOP_VEHICLE_VEH_POSZ, SHOP_VEHICLE_VEH_ANGLE, random(128), random(128), -1);
	SetVehicleVirtualWorld(PVar:playerID[VEHICLESHOP_VEHICLEID], GetPlayerVirtualWorld(playerID));

	FormatNew:string[256](LanguageString(playerID, StringID:79("%s~n~~n~Price: $%d")), g_vehicleModels[modelID - 400][E_VEHICLEMODEL_NAME], g_vehicleModels[modelID - 400][E_VEHICLEMODEL_PRICE]);
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], string);
}