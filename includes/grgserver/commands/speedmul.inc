PCMD:speedmul[ISADMIN](playerID, params[], StringID:248("Show or change the speed multiplier of your current vehicle"))
{
    new vehicleID = GetPlayerVehicleID(playerID);
    if (!vehicleID)
    {
        return COMMAND_NOT_IN_VEHICLE;
    }

    SendClientMessageEx(playerID, COLOR_INFO, StringID:249("Speed multiplier of your current vehicle: %f"), VehicleProperty:vehicleID[SPEEDMULTIPLIER]);

    new Float:multiplier;
    if (!sscanf(params, "f", multiplier))
    {
        VehicleProperty:vehicleID[SPEEDMULTIPLIER] = multiplier;
        SendClientMessageEx(playerID, COLOR_INFO, StringID:250("Speed multiplier of your current vehicle changed to: %f"), VehicleProperty:vehicleID[SPEEDMULTIPLIER]);
    }

    return COMMAND_OK;
}