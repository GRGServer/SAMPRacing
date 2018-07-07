Timer:ResetMoveObject(objectID)
{
    MoveObjectEx(objectID, Object:objectID[MOVE_TYPE], false, true);
}