PCMD:previewobjectmove[ISADMIN](playerID, params[], StringID:212("Preview the move of the last selected object"))
{
    if (!PVar:playerID[OBJEDITOR_LASTID])
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:213("You do not have a last selected object!"));
        return COMMAND_ERROR;
    }

    new objectID = PVar:playerID[OBJEDITOR_LASTID];

    if (!Object:objectID[MOVE_POSX] && !Object:objectID[MOVE_POSY] && !Object:objectID[MOVE_POSZ])
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:208("No target move position set!"));
        return COMMAND_ERROR;
    }

    MoveObjectEx(objectID, OBJECTMOVE_EDITORPREVIEW, true, false);

    return COMMAND_OK;
}