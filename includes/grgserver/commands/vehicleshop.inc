PCMD:vehicleshop[ISADMIN](playerID, params[], StringID:90("Enter the specified vehicle shop"))
{
	new shopID;
	if (sscanf(params, "d", shopID))
	{
		CmdUsageMsg(playerID, "vehicleshop", "ShopID");
		return COMMAND_USAGE;
	}

	if (shopID < 0 || shopID >= MAX_VEHICLESHOPS)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:91("Shop ID must be between 0 and %d"), MAX_VEHICLESHOPS);
		return COMMAND_ERROR;
	}

	EnterVehicleShop(playerID, shopID, true);
	return COMMAND_OK;
}