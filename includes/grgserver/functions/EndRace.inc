EndRace(playerID)
{
	new raceID = PVar:playerID[RACE_ID];

	if (raceID == -1)
	{
		return;
	}

	DisablePlayerRaceCheckpoint(playerID);

	PVar:playerID[RACE_ID] = -1;
	PVar:playerID[RACE_STARTED] = false;
	PVar:playerID[ALLOWCMDS] = true;

	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACE_BOTTOM]);

	SetPlayerVirtualWorld(playerID, 0);

	new vehicleID = GetPlayerVehicleID(playerID);
	if (vehicleID)
	{
		SetVehicleVirtualWorld(vehicleID, 0);
	}

	SetVehicleVirtualWorld(PVar:playerID[RACE_VEHICLEID], 0);

	// Check whether there is any other player in the race
	new foundPlayers;
	PlayerLoop(currentPlayerID)
	{
		if (PVar:currentPlayerID[RACE_ID] == raceID && !IsPlayerNPC(currentPlayerID))
		{
			foundPlayers = true;
			break;
		}
	}

	if (!foundPlayers)
	{
		// Change virtual world of all NPCs assigned to the race
		PlayerLoop(currentPlayerID)
		{
			if (PVar:currentPlayerID[RACE_ID] == raceID && IsPlayerNPC(currentPlayerID))
			{
				SendNPCCommand(currentPlayerID, NPCCMD_STOP);
				SetPlayerVirtualWorld(currentPlayerID, VIRTUALWORLD_IDLENPC);
			}
		}
	}
}