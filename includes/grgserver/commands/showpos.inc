PCMD:showpos[ISADMIN](playerID, params[], StringID:92("Toggle showing your current position"))
{
    if (PVar:playerID[SHOWPOS])
    {
        PVar:playerID[SHOWPOS] = false;
        PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS]);
        SendClientMessageEx(playerID, COLOR_INFO, StringID:96("Current position display has been disabled"));
    }
    else
    {
        PVar:playerID[SHOWPOS] = true;
        PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS]);
        SendClientMessageEx(playerID, COLOR_INFO, StringID:116("Current position display has been enabled"));
    }

    return COMMAND_OK;
}