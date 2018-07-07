PCMD:setgaragepickup[ISADMIN](playerID, params[], StringID:145("Set the pickup of a garage"))
{
    new garageID;
    if (sscanf(params, "d", garageID))
    {
        CmdUsageMsg(playerID, "setgaragepickup", "GarageID");
        return COMMAND_USAGE;
    }

    new garageNumber = -1;
    new freeGarageSlot = -1;
    Foreach(index, g_garages)
    {
        if (!g_garages[index][E_GARAGE_ID])
        {
            freeGarageSlot = index;
        }

        if (g_garages[index][E_GARAGE_ID] == garageID)
        {
            garageNumber = index;
            break;
        }
    }

    if (garageNumber == -1)
    {
        if (freeGarageSlot == -1)
        {
            SendClientMessageEx(playerID, COLOR_ERROR, StringID:138("Limit of %d garages reached!"), MAX_GARAGES);
            return COMMAND_ERROR;
        }

        garageNumber = freeGarageSlot;

        g_garages[garageNumber][E_GARAGE_ID] = garageID;
    }

    GetPlayerPos(playerID, g_garages[garageNumber][E_GARAGE_PICKUP_POSX], g_garages[garageNumber][E_GARAGE_PICKUP_POSY], g_garages[garageNumber][E_GARAGE_PICKUP_POSZ]);

    SaveGarages();

    UpdateGarage(garageNumber);

    SendClientMessageEx(playerID, COLOR_INFO, StringID:217("The garage pickup has been saved"));

    return COMMAND_OK;
}