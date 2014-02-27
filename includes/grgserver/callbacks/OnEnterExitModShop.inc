public OnEnterExitModShop(playerid, enterexit, interiorid)
{
	SetPrivateWorld(playerid, enterexit);
	SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), GetPlayerVirtualWorld(playerid));
}