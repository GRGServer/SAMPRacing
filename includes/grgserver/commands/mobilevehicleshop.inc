PCMD:mobilevehicleshop[HAS_MOBILEVEHICLESHOP](playerID, params[], StringID:127("Enable the mobile vehicle shop"))
{
    EnterVehicleShop(playerID, SHOP_VEHICLE_MOBILESHOPID, true);

    return COMMAND_OK;
}