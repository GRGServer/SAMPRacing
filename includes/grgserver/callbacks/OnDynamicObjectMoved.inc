public OnDynamicObjectMoved(objectid)
{
    new moveType = Object:objectid[MOVE_TYPE];
    new reverse = Object:objectid[MOVE_REVERSE];
    Object:objectid[MOVE_TYPE] = OBJECTMOVE_UNSET;
    Object:objectid[MOVE_REVERSE] = false;

    switch (moveType)
    {
        case OBJECTMOVE_AUTORESET:
        {
            if (reverse)
            {
                if (Object:objectid[MOVE_RESET_TIMER])
                {
                    KillTimer(Object:objectid[MOVE_RESET_TIMER]);
                    Object:objectid[MOVE_RESET_TIMER] = 0;
                }
            }
            else
            {
                if (Object:objectid[MOVE_RESET_TIMEOUT])
                {
                    if (Object:objectid[MOVE_RESET_TIMER])
                    {
                        KillTimer(Object:objectid[MOVE_RESET_TIMER]);
                    }
                    Object:objectid[MOVE_RESET_TIMER] = SetTimerEx("Timer_ResetMoveObject", Object:objectid[MOVE_RESET_TIMEOUT], false, "d", objectid);
                }
            }
        }
        case OBJECTMOVE_EDITORPREVIEW:
        {
            if (!reverse)
            {
                MoveObjectEx(objectid, moveType, false, true);
            }
        }
    }
}