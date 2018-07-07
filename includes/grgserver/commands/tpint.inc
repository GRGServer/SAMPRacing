PCMD:tpint[ISADMIN](playerID, params[], StringID:117("Teleport yourself to an interior"))
{
    new interiorID;
    if (sscanf(params, "d", interiorID))
    {
        CmdUsageMsg(playerID, "tpint", "InteriorID");
        return COMMAND_USAGE;
    }

    if (interiorID < 0 || interiorID >= MAX_INTERIORS)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:133("The interior ID must be between 0 and %d!"), MAX_INTERIORS - 1);
        return COMMAND_ERROR;
    }

    if (!StrNotNull(g_interiors[interiorID][E_INTERIOR_NAME]))
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:118("Unknown interior ID!"));
        return COMMAND_ERROR;
    }

    if (!TeleportToInterior(playerID, interiorID))
    {
        return COMMAND_ERROR;
    }

    SendClientMessageEx(playerID, COLOR_INFO, StringID:119("You teleported yourself to the interior '%s'"), g_interiors[interiorID][E_INTERIOR_NAME]);

    return COMMAND_OK;
}