TeleportTo(playerID, teleportID)
{
	SetPlayerPos(playerID, teleports[teleportID][TELEPORT_POSX], teleports[teleportID][TELEPORT_POSY], teleports[teleportID][TELEPORT_POSZ]);
	SetPlayerFacingAngle(playerID, teleports[teleportID][TELEPORT_ANGLE]);
	SetPlayerInterior(playerID, teleports[teleportID][TELEPORT_INTERIOR]);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:54("You got teleport to %s"), teleports[teleportID][TELEPORT_NAME]);
}