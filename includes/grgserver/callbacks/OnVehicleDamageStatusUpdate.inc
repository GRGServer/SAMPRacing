public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
    if (PVar:playerid[DRIFTING_STATE] && GetPlayerVehicleID(playerid) == vehicleid && GetPlayerVehicleSeat(playerid) == 0)
    {
        new panelsState;
        new doorsState;
        new lightsState;
        new tiresState;
        GetVehicleDamageStatus(vehicleid, panelsState, doorsState, lightsState, tiresState);
        if (panelsState || doorsState || lightsState || tiresState)
        {
            PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
            PVar:playerid[DRIFTING_ANGLEBONUS] = 0;
            PVar:playerid[DRIFTING_SCORE] = 0;
        }
    }
}