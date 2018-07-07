PCMD:god[ISADMIN](playerID, params[], StringID:64("Enable or disable god mode"))
{
    if (PVar:playerID[GODMODE])
    {
        PVar:playerID[GODMODE] = false;
        SendClientMessageEx(playerID, COLOR_INFO, StringID:65("God mode disabled"));
    }
    else
    {
        PVar:playerID[GODMODE] = true;
        SendClientMessageEx(playerID, COLOR_INFO, StringID:66("God mode enabled"));
    }

    return COMMAND_OK;
}