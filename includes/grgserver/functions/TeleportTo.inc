TeleportTo(playerID, teleportID, whileFading = false)
{
	if (whileFading)
	{
		new vehicleID = GetPlayerVehicleID(playerID);
		new seat = GetPlayerVehicleSeat(playerID);

		SetPlayerPos(playerID, g_teleports[teleportID][E_TELEPORT_POSX], g_teleports[teleportID][E_TELEPORT_POSY], g_teleports[teleportID][E_TELEPORT_POSZ]);
		SetPlayerFacingAngle(playerID, g_teleports[teleportID][E_TELEPORT_ANGLE]);
		SetPlayerInterior(playerID, g_teleports[teleportID][E_TELEPORT_INTERIOR]);

		// Reset virtual world (The player could be in a mod shop or something else using a virtual world)
		SetPlayerVirtualWorld(playerID, 0);

		if (g_teleports[teleportID][E_TELEPORT_WITHVEHICLE] && seat == 0)
		{
			SetVehiclePos(vehicleID, g_teleports[teleportID][E_TELEPORT_POSX], g_teleports[teleportID][E_TELEPORT_POSY], g_teleports[teleportID][E_TELEPORT_POSZ]);
			LinkVehicleToInterior(vehicleID, g_teleports[teleportID][E_TELEPORT_INTERIOR]);
			PutPlayerInVehicle(playerID, vehicleID, seat);

			// Reset virtual world (The player could be in a mod shop or something else using a virtual world)
			SetVehicleVirtualWorld(vehicleID, 0);
		}

		SetCameraBehindPlayer(playerID);

		SendClientMessageEx(playerID, COLOR_INFO, StringID:54("You got teleport to %s"), g_teleports[teleportID][E_TELEPORT_NAME]);

		FadeInScreen(playerID, 5, SCREENFADER_TELEPORT);
	}
	else
	{
		PVar:playerID[TELEPORTID] = teleportID;

		FadeOutScreen(playerID, 5, 0, 0, 0, SCREENFADER_TELEPORT);
	}
}