public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PVar:playerid[VEHICLESHOP_ISINSIDE])
	{
		if (IsKeyPressed(KEY_ANALOG_LEFT))
		{
			PVar:playerid[VEHICLESHOP_MODELID] = FindNextVehicleModel(PVar:playerid[VEHICLESHOP_MODELID], "Car", false);
			CreateVehicleShopVehicle(playerid);
		}
		else if (IsKeyPressed(KEY_ANALOG_RIGHT))
		{
			PVar:playerid[VEHICLESHOP_MODELID] = FindNextVehicleModel(PVar:playerid[VEHICLESHOP_MODELID], "Car", true);
			CreateVehicleShopVehicle(playerid);
		}
		else if (IsKeyPressed(KEY_SPRINT))
		{
			new price = g_vehicleModels[PVar:playerid[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE];
			if (GetPlayerMoney(playerid) < price)
			{
				GameTextForPlayer(playerid, LanguageString(playerid, StringID:80("You do not have enough money!")), 3000, 3);
			}
			else
			{
				ShowDialog:ConfirmVehicleBuy(playerid);
			}
		}
		else if (IsKeyPressed(KEY_SECONDARY_ATTACK))
		{
			ExitVehicleShop(playerid, false);
		}
	}
}