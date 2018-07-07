CMD:engine(playerID, params[], StringID:18("Start or turn off the engine of your vehicle"))
{
    if (!IsPlayerInAnyVehicle(playerID))
    {
        return COMMAND_NOT_IN_VEHICLE;
    }

    if (GetPlayerVehicleSeat(playerID) != 0)
    {
        return COMMAND_NOT_VEHICLE_DRIVER;
    }

    new vehicleID = GetPlayerVehicleID(playerID);
    if (GetVehicleEngineState(vehicleID))
    {
        SetVehicleEngineState(vehicleID, false);
        SendClientMessageEx(playerID, COLOR_INFO, StringID:20("The engine of your vehicle has been turned off"));
    }
    else
    {
        SetVehicleEngineState(vehicleID, true);
        SendClientMessageEx(playerID, COLOR_INFO, StringID:21("The engine of your vehicle has been started"));
    }

    return COMMAND_OK;
}