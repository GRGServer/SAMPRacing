UpdateObjectEditorInfo(playerID, show)
{
    if (show)
    {
        new Float:posX;
        new Float:posY;
        new Float:posZ;
        new Float:rotX;
        new Float:rotY;
        new Float:rotZ;
        GetDynamicObjectPos(PVar:playerID[OBJEDITOR_ID], posX, posY, posZ);
        GetDynamicObjectRot(PVar:playerID[OBJEDITOR_ID], rotX, rotY, rotZ);

        FormatNew:string[200](LanguageString(playerID, StringID:46("%s~n~Position: %f x %f x %f~n~Rotation: %f x %f x %f")), PVar:playerID[OBJEDITOR_MODELNAME], posX, posY, posZ, rotX, rotY, rotZ);
        PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], string);
        PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO]);
    }
    else
    {
        PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO]);
    }
}