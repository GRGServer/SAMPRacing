AddObject(playerID, modelID, copyFromCurrent = false)
{
	new Float:posX;
	new Float:posY;
	new Float:posZ;
	new Float:rotX;
	new Float:rotY;
	new Float:rotZ;

	if (copyFromCurrent)
	{
		GetDynamicObjectPos(PVar:playerID[OBJEDITOR_ID], posX, posY, posZ);
		GetDynamicObjectRot(PVar:playerID[OBJEDITOR_ID], rotX, rotY, rotZ);
	}
	else
	{
		GetPlayerPos(playerID, posX, posY, posZ);
	}

	new objectID = CreateDynamicObject(modelID, posX, posY, posZ, rotX, rotY, rotZ);
	if (objectID > MAX_DYNAMIC_OBJECTS)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:101("Limit of %d objects reached!"), MAX_DYNAMIC_OBJECTS);
		return false;
	}

	EditDynamicObject(playerID, objectID);

	strcat(Object:objectID[FILENAME], "uncategorized", STRINGLENGTH_OBJECTFILENAME);

	Object:objectID[ORIGINAL_POSX] = posX;
	Object:objectID[ORIGINAL_POSY] = posY;
	Object:objectID[ORIGINAL_POSZ] = posZ;
	Object:objectID[ORIGINAL_ROTX] = rotX;
	Object:objectID[ORIGINAL_ROTY] = rotY;
	Object:objectID[ORIGINAL_ROTZ] = rotZ;

	new name[STRINGLENGTH_OBJECTMODELNAME];
	Foreach(index, g_objectModels)
	{
		if (g_objectModels[index][E_OBJECTMODEL_ID] == modelID)
		{
			strcat(name, g_objectModels[index][E_OBJECTMODEL_NAME]);
			break;
		}
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:104("The object %d (%s) has been added and selected for editing"), modelID, name);

	return true;
}