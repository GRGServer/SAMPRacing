TeleportTo(playerID, teleportID)
{
	new vehicleID = GetPlayerVehicleID(playerID);
	new seat = GetPlayerVehicleSeat(playerID);

	SetPlayerPos(playerID, teleports[teleportID][TELEPORT_POSX], teleports[teleportID][TELEPORT_POSY], teleports[teleportID][TELEPORT_POSZ]);
	SetPlayerFacingAngle(playerID, teleports[teleportID][TELEPORT_ANGLE]);
	SetPlayerInterior(playerID, teleports[teleportID][TELEPORT_INTERIOR]);

	if (teleports[teleportID][TELEPORT_WITHVEHICLE] && seat == 0)
	{
		PutPlayerInVehicle(playerID, vehicleID, seat);
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:54("You got teleport to %s"), teleports[teleportID][TELEPORT_NAME]);
}