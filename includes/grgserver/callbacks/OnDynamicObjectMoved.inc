public OnDynamicObjectMoved(objectid)
{
	new moveType = Object:objectid[MOVE_TYPE];
	Object:objectid[MOVE_TYPE] = OBJECTMOVE_UNSET;

	switch (moveType)
	{
		case OBJECTMOVE_EDITORPREVIEW:
		{
			// TODO: What to do after movement finished?
		}
	}
}