TeleportTo(playerID, teleportID)
{
	new vehicleID = GetPlayerVehicleID(playerID);
	new seat = GetPlayerVehicleSeat(playerID);

	SetPlayerPos(playerID, g_teleports[teleportID][E_TELEPORT_POSX], g_teleports[teleportID][E_TELEPORT_POSY], g_teleports[teleportID][E_TELEPORT_POSZ]);
	SetPlayerFacingAngle(playerID, g_teleports[teleportID][E_TELEPORT_ANGLE]);
	SetPlayerInterior(playerID, g_teleports[teleportID][E_TELEPORT_INTERIOR]);

	if (g_teleports[teleportID][E_TELEPORT_WITHVEHICLE] && seat == 0)
	{
		SetVehiclePos(vehicleID, g_teleports[teleportID][E_TELEPORT_POSX], g_teleports[teleportID][E_TELEPORT_POSY], g_teleports[teleportID][E_TELEPORT_POSZ]);
		PutPlayerInVehicle(playerID, vehicleID, seat);
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:54("You got teleport to %s"), g_teleports[teleportID][E_TELEPORT_NAME]);
}