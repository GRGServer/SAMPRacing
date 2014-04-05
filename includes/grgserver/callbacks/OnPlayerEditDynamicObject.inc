public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	switch (response)
	{
		case EDIT_RESPONSE_CANCEL:
		{
			Object:objectid[MOVE_TYPE] = OBJECTMOVE_EDIT;
			MoveDynamicObject(objectid, Object:objectid[ORIGINAL_POSX], Object:objectid[ORIGINAL_POSY], Object:objectid[ORIGINAL_POSZ], 10.0, Object:objectid[ORIGINAL_ROTX], Object:objectid[ORIGINAL_ROTY], Object:objectid[ORIGINAL_ROTZ]);

			PVar:playerid[OBJEDITOR_ID] = 0;

			UpdateObjectEditorInfo(playerid, false);

			SelectObject(playerid);
		}
		case EDIT_RESPONSE_FINAL:
		{
			Object:objectid[MOVE_TYPE] = OBJECTMOVE_EDIT;
			MoveDynamicObject(objectid, x, y, z, 10.0, rx, ry, rz);

			Object:objectid[ORIGINAL_POSX] = x;
			Object:objectid[ORIGINAL_POSY] = y;
			Object:objectid[ORIGINAL_POSZ] = z;
			Object:objectid[ORIGINAL_ROTX] = rx;
			Object:objectid[ORIGINAL_ROTY] = ry;
			Object:objectid[ORIGINAL_ROTZ] = rz;

			SaveObjects(Object:objectid[FILENAME]);
			PVar:playerid[OBJEDITOR_ID] = 0;
			PlaySound(playerid, SOUND_OBJECTPLACED);

			UpdateObjectEditorInfo(playerid, false);

			SelectObject(playerid);
			SendClientMessageEx(playerid, COLOR_INFO, StringID:100("The changes have been saved"));
		}
		default:
		{
			Object:objectid[MOVE_TYPE] = OBJECTMOVE_EDIT;
			MoveDynamicObject(objectid, x, y, z, 10.0, rx, ry, rz);

			UpdateObjectEditorInfo(playerid, true);
		}
	}
}