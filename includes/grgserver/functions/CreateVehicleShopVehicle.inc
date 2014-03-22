CreateVehicleShopVehicle(playerID)
{
	if (PVar:playerID[VEHICLESHOP_VEHICLEID] != INVALID_VEHICLE_ID)
	{
		DestroyVehicleEx(PVar:playerID[VEHICLESHOP_VEHICLEID]);
	}

	new modelID = PVar:playerID[VEHICLESHOP_MODELID];
	new shopID = PVar:playerID[VEHICLESHOP_ID];

	PVar:playerID[VEHICLESHOP_VEHICLEID] = CreateVehicle(modelID, SHOP_VEHICLE_VEH_POSX, SHOP_VEHICLE_VEH_POSY, SHOP_VEHICLE_VEH_POSZ, SHOP_VEHICLE_VEH_ANGLE, random(128), random(128), -1);

	if (IsValidNumberPlateVehicle(PVar:playerID[VEHICLESHOP_VEHICLEID]))
	{
		new numberPlateText[STRINGLENGTH_NUMBERPLATE];
		numberPlateText = GenerateNumberPlateText(g_vehicleShops[shopID][E_VEHICLESHOP_NUMBERPLATEPREFIX]);
		if (StrNotNull(numberPlateText))
		{
			SetVehicleNumberPlate(PVar:playerID[VEHICLESHOP_VEHICLEID], numberPlateText);
		}
	}

	SetVehicleVirtualWorld(PVar:playerID[VEHICLESHOP_VEHICLEID], GetPlayerVirtualWorld(playerID));

	FormatNew:string[256](LanguageString(playerID, StringID:79("%s~n~~n~Price: $%s")), g_vehicleModels[modelID - 400][E_VEHICLEMODEL_NAME], FormatNumber(g_vehicleModels[modelID - 400][E_VEHICLEMODEL_PRICE], 0, '.', ','));
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], string);
}