public OnPlayerConnect(playerid)
{
    // Reset all player variables to their default values
    ResetPlayerVariables(playerid);

    if (IsPlayerNPC(playerid))
    {
        new ip[16];// TODO: Increase for IPv6 (Once supported in SA-MP)
        GetPlayerIp(playerid, ip, sizeof(ip));

        // NPC not spawned from localhost -> Bad NPC
        if (!IsStr(ip, "127.0.0.1"))
        {
            print("IP address of NPC does not equal 127.0.0.1! Kicking...");
            Kick(playerid);
            return true;
        }

        new prefix[MAX_PLAYER_NAME];
        new npcID;
        sscanf(GetPlayerNameEx(playerid), "p<_>s[10]d", prefix, npcID);

        // NPC name does not match the requied format -> Bad NPC
        if (!IsStr(prefix, "NPC") || npcID < 0 || npcID >= MAX_NPCS)
        {
            print("Invalid NPC name! Kicking...");
            Kick(playerid);
            return true;
        }

        if (g_npcs[npcID][E_NPC_VEHICLE_MODELID])
        {
            g_npcs[npcID][E_NPC_VEHICLE_ID] = CreateVehicleEx(g_npcs[npcID][E_NPC_VEHICLE_MODELID], 0, 0, 0, 0, -1, -1);
            new vehicleID = g_npcs[npcID][E_NPC_VEHICLE_ID];

            if (vehicleID != INVALID_VEHICLE_ID)
            {
                if (g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB] != -1)
                {
                    VehicleProperty:vehicleID[PAINTJOBID] = g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB];
                    ChangeVehiclePaintjob(vehicleID, g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB]);
                }

                Count(componentSlot, MAX_VEHICLECOMPONENT_SLOTS)
                {
                    if (g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot])
                    {
                        AddVehicleComponent(vehicleID, g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot]);
                    }
                }
            }
        }

        SetSpawnInfo(playerid, 0, g_npcs[npcID][E_NPC_SKIN], 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        // Assign the NPC ID to the PVar
        PVar:playerid[NPCID] = npcID;

        // Send a "set recording" command to the NPC
        FormatNew:command[100]("%s %d %s", NPCCMD_SETRECORDING, g_npcs[npcID][E_NPC_RECORDING_TYPE], g_npcs[npcID][E_NPC_RECORDING_NAME]);
        SendNPCCommand(playerid, command);

        Foreach(raceID, g_races)
        {
            new foundRaceNPC;
            Count(raceNPCID, MAX_RACENPCS)
            {
                if (g_races[raceID][E_RACE_NPCS][raceNPCID] == npcID)
                {
                    PVar:playerid[RACE_ID] = raceID;
                    PVar:playerid[RACE_VEHICLEID] = g_npcs[npcID][E_NPC_VEHICLE_ID];

                    foundRaceNPC = true;
                    break;
                }
            }

            if (foundRaceNPC)
            {
                break;
            }
        }

        return true;
    }

    printf("%s connected from %s", GetPlayerNameEx(playerid), GetPlayerCountryName(playerid));

    SendDeathMessage(INVALID_PLAYER_ID, playerid, ICON_CONNECT);

    // Send join message to all players except the joined player
    PlayerLoop(playerID)
    {
        if (!IsPlayerNPC(playerID) && playerID != playerid)
        {
            SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:23("%u has joined the server"), playerid);
        }
    }

    // Remove standard objects
    RemoveStandardObjectsForPlayer(playerid);

    // Check whether the player is already registered
    MySQLFormat("SELECT `id`, `language` FROM `users` WHERE `username` = '%e'", GetPlayerNameEx(playerid));
    mysql_pquery(g_mysql, g_sqlQuery, "OnPlayerRegisteredCheck", "d", playerid);

    TextDrawShowForPlayer(playerid, g_textDrawClock);

    return true;
}