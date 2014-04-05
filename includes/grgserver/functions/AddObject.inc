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

	PVar:playerID[OBJEDITOR_ID] = objectID;

	PVar:playerID[OBJEDITOR_MODELNAME] = GetObjectNameByModelID(modelID);

	UpdateObjectEditorInfo(playerID, true);

	EditDynamicObject(playerID, objectID);

	strcat(Object:objectID[FILENAME], PVar:playerID[OBJEDITOR_FILENAME], STRINGLENGTH_OBJECTFILENAME);

	Object:objectID[ORIGINAL_POSX] = posX;
	Object:objectID[ORIGINAL_POSY] = posY;
	Object:objectID[ORIGINAL_POSZ] = posZ;
	Object:objectID[ORIGINAL_ROTX] = rotX;
	Object:objectID[ORIGINAL_ROTY] = rotY;
	Object:objectID[ORIGINAL_ROTZ] = rotZ;

	Object:objectID[MOVE_SPEED] = 10;

	SendClientMessageEx(playerID, COLOR_INFO, StringID:104("The object %d (%s) has been added to file '%s' and selected for editing"), modelID, PVar:playerID[OBJEDITOR_MODELNAME], Object:objectID[FILENAME]);

	return true;
}