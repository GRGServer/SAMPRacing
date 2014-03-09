CMD:mobilevehicleshop(playerID, params[], StringID:127("Enable the mobile vehicle shop"))
{
	if (!PVar:playerID[HAS_MOBILEVEHICLESHOP])
	{
		return COMMAND_PERMISSION_DENIED;
	}

	EnterVehicleShop(playerID, SHOP_VEHICLE_MOBILESHOPID, true);

	return COMMAND_OK;
}