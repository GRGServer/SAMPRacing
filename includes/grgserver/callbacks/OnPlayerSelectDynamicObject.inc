public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
	PVar:playerid[OBJEDITOR_ID] = objectid;

	EditDynamicObject(playerid, objectid);

	new modelID = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_MODEL_ID);
	new objectIndex;
	Foreach(index, g_objectModels)
	{
		if (g_objectModels[index][E_OBJECTMODEL_ID] == modelID)
		{
			objectIndex = index;
			break;
		}
	}

	SendClientMessageEx(playerid, COLOR_INFO, StringID:102("Object '%s from file '%s' selected"), g_objectModels[objectIndex][E_OBJECTMODEL_NAME], Object:objectid[FILENAME]);
	SendClientMessageEx(playerid, COLOR_INFO, StringID:103("You can now edit the object using the GUI, clone it (Key %s) or remove it (Key %s)"), GetGameTextKeyByID(KEY_OBJECTEDITOR_CLONE, IsPlayerInAnyVehicle(playerid)), GetGameTextKeyByID(KEY_OBJECTEDITOR_REMOVE, IsPlayerInAnyVehicle(playerid)));
}