public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
    PVar:playerid[OBJEDITOR_ID] = objectid;
    PVar:playerid[OBJEDITOR_LASTID] = objectid;

    PVar:playerid[OBJEDITOR_MODELNAME] = GetObjectNameByModelID(modelid);

    UpdateObjectEditorInfo(playerid, true);

    EditDynamicObject(playerid, objectid);

    SendClientMessageEx(playerid, COLOR_INFO, StringID:102("Object '%s' from file '%s' selected"), PVar:playerid[OBJEDITOR_MODELNAME], Object:objectid[FILENAME]);
    SendClientMessageEx(playerid, COLOR_INFO, StringID:103("You can now edit the object using the GUI, clone it (Key %s) or remove it (Key %s)"), GetGameTextKeyByID(KEY_OBJECTEDITOR_CLONE, IsPlayerInAnyVehicle(playerid)), GetGameTextKeyByID(KEY_OBJECTEDITOR_REMOVE, IsPlayerInAnyVehicle(playerid)));
    SendClientMessageEx(playerid, COLOR_INFO, StringID:209("The target move position can be set by pressing key %s"), GetGameTextKeyByID(KEY_OBJECTEDITOR_SETMOVEPOS, IsPlayerInAnyVehicle(playerid)));
}