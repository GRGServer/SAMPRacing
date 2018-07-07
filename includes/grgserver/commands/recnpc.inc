PCMD:recnpc[ISADMIN](playerID, params[], StringID:187("Record a new NPC and optionally playback other NPCs"))
{
    new name[STRINGLENGTH_NPCRECORDINGNAME];
    new playNPCs[200];
    if (sscanf(params, "s[" #STRINGLENGTH_NPCRECORDINGNAME "]s[200]", name, playNPCs))
    {
        if (sscanf(params, "s[" #STRINGLENGTH_NPCRECORDINGNAME "]", name))
        {
            CmdUsageMsg(playerID, "recnpc", "Name", "[NPC1]", "[NPC2]", "[...]");
            return COMMAND_USAGE;
        }
    }

    new npcSlot = -1;
    Foreach(npcID, g_npcs)
    {
        if (g_npcs[npcID][E_NPC_ID] == -1)
        {
            npcSlot = npcID;
            break;
        }
    }

    if (npcSlot == -1)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:188("Limit of %d NPCs reached!"), MAX_NPCS);
        return COMMAND_ERROR;
    }

    PVar:playerID[RECNPC_NPCID] = npcSlot;

    if (IsPlayerInAnyVehicle(playerID))
    {
        PVar:playerID[RECNPC_TYPE] = PLAYER_RECORDING_TYPE_DRIVER;
    }
    else
    {
        PVar:playerID[RECNPC_TYPE] = PLAYER_RECORDING_TYPE_ONFOOT;
    }

    PVar:playerID[RECNPC_NAME] = name;

    new playNPCsArray[MAX_RECNPC_PLAYNPCS][MAX_PLAYER_NAME];
    explode(playNPCs, playNPCsArray);

    Count(npcID, MAX_RECNPC_PLAYNPCS)
    {
        PVar:playerID[RECNPC_PLAYNPCS][npcID] = -1;
    }

    new connectedPlayNPCs;
    Foreach(playNPCsIndex, playNPCsArray)
    {
        if (StrNotNull(playNPCsArray[playNPCsIndex]))
        {
            new npcFound;
            new requestedNPCID = strval(playNPCsArray[playNPCsIndex]);
            Foreach(npcID, g_npcs)
            {
                if (g_npcs[npcID][E_NPC_ID] == requestedNPCID)
                {
                    PVar:playerID[RECNPC_PLAYNPCS][connectedPlayNPCs] = npcID;

                    connectedPlayNPCs++;
                    npcFound = true;
                    break;
                }
            }

            if (!npcFound)
            {
                SendClientMessageEx(playerID, COLOR_ERROR, StringID:202("Invalid NPC ID '%d'!"), requestedNPCID);
                return COMMAND_ERROR;
            }
        }
    }

    ShowDialog:ConfirmStartNPCRecording(playerID);

    return COMMAND_OK;
}