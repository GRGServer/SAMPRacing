PCMD:showareas[ISADMIN](playerID, params[], StringID:125("Show a list of areas you are currently in"))
{
    new areaCount = GetPlayerNumberDynamicAreas(playerID);
    if (areaCount)
    {
        SendClientMessageEx(playerID, COLOR_INFO, StringID:73("You are in the following areas:"));

        new areas[MAX_AREAS];
        GetPlayerDynamicAreas(playerID, areas);
        Count(index, areaCount)
        {
            new areaID = Streamer_GetIntData(STREAMER_TYPE_AREA, areas[index], E_STREAMER_EXTRA_ID);
            SendClientMessage(playerID, COLOR_SYSTEM, g_areas[areaID][E_AREA_NAME]);
        }
    }
    else
    {
        SendClientMessageEx(playerID, COLOR_INFO, StringID:74("You are not in any area"));
    }

    return COMMAND_OK;
}