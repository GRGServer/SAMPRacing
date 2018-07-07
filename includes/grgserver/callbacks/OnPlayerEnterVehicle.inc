public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    // The player is in a race which has been started
    if (PVar:playerid[RACE_ID] != -1 && PVar:playerid[RACE_STARTED])
    {
        if (vehicleid == PVar:playerid[RACE_VEHICLEID])
        {
            if (PVar:playerid[RACE_DISQUALIFY_TIMER])
            {
                KillTimer(PVar:playerid[RACE_DISQUALIFY_TIMER]);
            }
        }
    }
}