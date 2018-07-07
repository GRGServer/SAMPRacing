ExitGarage(playerID, withVehicle)
{
    // Prevent exit while loading the vehicle
    if (PVar:playerID[GARAGE_VEHICLE_LOADING])
    {
        return;
    }

    PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_CTRL_INFO]);
    PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_VEHICLE_INFO]);

    SetPlayerVirtualWorld(playerID, 0);

    new garageNumber = PVar:playerID[GARAGE_NUMBER];

    SetPlayerSpawn(playerID, SPAWNTYPE_EXITGARAGE, g_garages[garageNumber][E_GARAGE_VEHICLE_POSX], g_garages[garageNumber][E_GARAGE_VEHICLE_POSY], g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ], g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE]);

    if (!withVehicle)
    {
        DestroyVehicleEx(PVar:playerID[GARAGE_VEHICLE_ID]);

        PVar:playerID[GARAGE_VEHICLE_ID] = INVALID_VEHICLE_ID;
    }

    TogglePlayerSpectating(playerID, false);

    PVar:playerID[ALLOWCMDS] = true;
}