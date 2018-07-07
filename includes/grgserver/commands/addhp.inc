PCMD:addhp[ISADMIN](playerID, params[], StringID:242("Add a new hidden package"))
{
    Foreach(packageID, g_hiddenPackages)
    {
        new Float:posX = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX];
        new Float:posY = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY];
        new Float:posZ = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ];

        if (!posX && !posY && !posZ)
        {
            GetPlayerPos(playerID, g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ]);
            SaveHiddenPackages();

            SendClientMessageEx(playerID, COLOR_INFO, StringID:243("Hidden package created. It will appear on next reload."));
            return COMMAND_OK;
        }
    }

    SendClientMessageEx(playerID, COLOR_ERROR, StringID:244("Limit of %d hidden packages reached!"), MAX_HIDDENPACKAGES);
    return COMMAND_ERROR;
}