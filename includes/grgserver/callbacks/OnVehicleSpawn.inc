public OnVehicleSpawn(vehicleid)
{
    DeleteVehicle(vehicleid);

    PlayerLoop(playerID)
    {
        if (PVar:playerID[RACE_ID] != -1 && PVar:playerID[RACE_STARTED] && PVar:playerID[RACE_VEHICLEID] == vehicleid)
        {
            DisqualifyRacePlayer(playerID);
            break;
        }
    }
}