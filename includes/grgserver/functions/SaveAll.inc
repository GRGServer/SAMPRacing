SaveAll()
{
    // Players
    LoggedInPlayers(playerID)
    {
        SavePlayer(playerID);
    }

    // Vehicles
    Count1(vehicleID, MAX_VEHICLES)
    {
        SaveVehicle(vehicleID);
    }
}