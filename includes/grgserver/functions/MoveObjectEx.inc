MoveObjectEx(objectID, type, fromOriginalStart, reverse)
{
	if (fromOriginalStart)
	{
		if (reverse)
		{
			SetDynamicObjectPos(objectID, Object:objectID[MOVE_POSX], Object:objectID[MOVE_POSY], Object:objectID[MOVE_POSZ]);
			SetDynamicObjectRot(objectID, Object:objectID[MOVE_ROTX], Object:objectID[MOVE_ROTY], Object:objectID[MOVE_ROTZ]);
		}
		else
		{
			SetDynamicObjectPos(objectID, Object:objectID[ORIGINAL_POSX], Object:objectID[ORIGINAL_POSY], Object:objectID[ORIGINAL_POSZ]);
			SetDynamicObjectRot(objectID, Object:objectID[ORIGINAL_ROTX], Object:objectID[ORIGINAL_ROTY], Object:objectID[ORIGINAL_ROTZ]);
		}
	}

	Object:objectID[MOVE_TYPE] = type;
	Object:objectID[MOVE_REVERSE] = reverse;

	if (reverse)
	{
		MoveDynamicObject(objectID, Object:objectID[ORIGINAL_POSX], Object:objectID[ORIGINAL_POSY], Object:objectID[ORIGINAL_POSZ], Object:objectID[MOVE_SPEED], Object:objectID[ORIGINAL_ROTX], Object:objectID[ORIGINAL_ROTY], Object:objectID[ORIGINAL_ROTZ]);
	}
	else
	{
		MoveDynamicObject(objectID, Object:objectID[MOVE_POSX], Object:objectID[MOVE_POSY], Object:objectID[MOVE_POSZ], Object:objectID[MOVE_SPEED], Object:objectID[MOVE_ROTX], Object:objectID[MOVE_ROTY], Object:objectID[MOVE_ROTZ]);
	}
}