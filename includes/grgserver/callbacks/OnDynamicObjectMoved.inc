public OnDynamicObjectMoved(objectid)
{
	new moveType = Object:objectid[MOVE_TYPE];
	new reverse = Object:objectid[MOVE_REVERSE];
	Object:objectid[MOVE_TYPE] = OBJECTMOVE_UNSET;
	Object:objectid[MOVE_REVERSE] = false;

	switch (moveType)
	{
		case OBJECTMOVE_EDITORPREVIEW:
		{
			if (!reverse)
			{
				MoveObjectEx(objectid, moveType, false, true);
			}
		}
	}
}