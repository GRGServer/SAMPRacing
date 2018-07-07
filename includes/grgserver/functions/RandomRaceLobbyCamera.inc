RandomRaceLobbyCamera(playerID)
{
    if (PVar:playerID[RACE_LOBBYNPC] == RACE_LOBBY_NPC1)
    {
        PVar:playerID[RACE_LOBBYNPC] = RACE_LOBBY_NPC2;
    }
    else
    {
        PVar:playerID[RACE_LOBBYNPC] = RACE_LOBBY_NPC1;
    }

    new npcID = -1;
    Foreach(arrayIndex, g_npcs)
    {
        if (g_npcs[arrayIndex][E_NPC_ID] == PVar:playerID[RACE_LOBBYNPC])
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