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
        new npcIndex;
        for (new player = players + 1; player <= RACE_PLAYERCOUNT; player++)
        {
            if (npcIndex >= MAX_RACENPCS)
            {
                break;
            }

            if (g_races[raceID][E_RACE_NPCS][npcIndex] != -1)
            {
                PlayerLoop(currentPlayerID)
                {
                    if (IsPlayerNPC(currentPlayerID) && PVar:currentPlayerID[NPCID] == g_races[raceID][E_RACE_NPCS][npcIndex])
                    {
                        new npcID = g_races[raceID][E_RACE_NPCS][npcIndex];
                        SetPlayerVirtualWorld(currentPlayerID, VIRTUALWORLD_RACE + raceID);
                        SetVehicleVirtualWorld(g_npcs[npcID][E_NPC_VEHICLE_ID], VIRTUALWORLD_RACE + raceID);
                        PutPlayerInVehicle(currentPlayerID, g_npcs[npcID][E_NPC_VEHICLE_ID], 0);
                        SendNPCCommand(currentPlayerID, NPCCMD_START);
                        break;
                    }
                }
            }

            npcIndex++;
        }

        KillTimer(g_races[raceID][E_RACE_COUNTDOWNTIMER]);
        return;
    }

    g_races[raceID][E_RACE_COUNTDOWN]--;
}