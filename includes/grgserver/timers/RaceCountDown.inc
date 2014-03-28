Timer:RaceCountDown(raceID)
{
	new players;
	PlayerLoop(playerID)
	{
		if (PVar:playerID[RACE_ID] == raceID && !IsPlayerNPC(playerID))
		{
			players++;

			new string[10];

			if (g_races[raceID][E_RACE_COUNTDOWN])
			{
				Format:string("~r~%d", g_races[raceID][E_RACE_COUNTDOWN]);
			}
			else
			{
				Format:string("~g~%s", LanguageString(playerID, StringID:186("Go!")));

				TogglePlayerControllable(playerID, true);
			}

			GameTextForPlayer(playerID, string, 3000, 6);
		}
	}

	if (!g_races[raceID][E_RACE_COUNTDOWN])
	{
		// Add NPCs if required player count not reached
		new npcID;
		for (new player = players + 1; player <= RACE_PLAYERCOUNT; player++)
		{
			if (npcID >= MAX_RACENPCS)
			{
				break;
			}

			if (g_races[raceID][E_RACE_NPCS][npcID] != -1)
			{
				PlayerLoop(currentPlayerID)
				{
					if (IsPlayerNPC(currentPlayerID) && PVar:currentPlayerID[NPCID] == g_races[raceID][E_RACE_NPCS][npcID])
					{
						SetPlayerVirtualWorld(currentPlayerID, VIRTUALWORLD_RACE + raceID);
						SetVehicleVirtualWorld(GetPlayerVehicleID(currentPlayerID), VIRTUALWORLD_RACE + raceID);
						SendNPCCommand(currentPlayerID, NPCCMD_START);
						break;
					}
				}
			}

			npcID++;
		}

		KillTimer(g_races[raceID][E_RACE_COUNTDOWNTIMER]);
		return;
	}

	g_races[raceID][E_RACE_COUNTDOWN]--;
}