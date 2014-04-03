RandomRaceLobbyCamera(playerID)
{
	//if (random(2))
	//{
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
		PlayerSpectateVehicle(playerID, g_npcs[npcID][E_NPC_VEHICLE_ID], SPECTATE_MODE_NORMAL);// TODO: Does not work after playing a camera movement

		SetTimerEx("Timer_RandomRaceLobbyCamera", RACE_LOBBY_NPCSPECTATETIME, false, "d", playerID);
	/*}
	else
	{
		// TODO: Requires camera movements
		new cameraMovements[MAX_CAMERAMOVEMENTS];

		new movementIndex;
		Foreach(arrayIndex, g_cameraMovements)
		{
			if (g_cameraMovements[arrayIndex][E_CAMERAMOVEMENT_TYPE] == CAMMOVEMENT_RACELOBBY)
			{
				cameraMovements[movementIndex] = arrayIndex;
				movementIndex++;
			}
		}

		PlayCameraMovement(playerID, cameraMovements[random(movementIndex)], 3000);
	}*/
}