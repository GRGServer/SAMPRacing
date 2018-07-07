public OnEnterExitModShop(playerid, enterexit, interiorid)
{
    if (enterexit)
    {
        SetPlayerVirtualWorld(playerid, VIRTUALWORLD_MODSHOP + playerid);
        SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), VIRTUALWORLD_MODSHOP + playerid);
    }
    else
    {
        SetPlayerVirtualWorld(playerid, 0);
        SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), 0);
    }
}