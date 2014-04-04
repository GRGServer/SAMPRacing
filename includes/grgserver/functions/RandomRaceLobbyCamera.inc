RandomRaceLobbyCamera(playerID)
{
	new searchNPCID;
	if (random(2))
	{
		searchNPCID = RACE_LOBBY_NPC1;
	}
	else
	{
		searchNPCID = RACE_LOBBY_NPC2;
	}

	new npcID = -1;
	Foreach(arrayIndex, g_npcs)
	{
		if (g_npcs[arrayIndex][E_NPC_ID] == searchNPCID)
		{
			npcID = arrayIndex;
			break;
		}
	}

	// Something failed...
	if (npcID == -1)
	{
		return;
	}

	SetPlayerInterior(playerID, g_npcs[npcID][E_NPC_INTERIOR]);
	PlayerSpectateVehicle(playerID, g_npcs[npcID][E_NPC_VEHICLE_ID], SPECTATE_MODE_NORMAL);

	SetTimerEx("Timer_RandomRaceLobbyCamera", RACE_LOBBY_NPCSPECTATETIME, false, "d", playerID);
}