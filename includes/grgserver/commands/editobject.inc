PCMD:editobject[ISADMIN](playerID, params[], StringID:111("Enable the object selection mode to select and edit objects"))
{
    SelectObject(playerID);

    SendClientMessageEx(playerID, COLOR_INFO, StringID:112("Object selection mode enabled"));

    return COMMAND_OK;
}