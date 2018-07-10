GetDynamicPickupPos(pickupID, &Float:posX, &Float:posY, &Float:posZ)
{
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupID, E_STREAMER_X, posX);
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupID, E_STREAMER_Y, posY);
    Streamer_GetFloatData(STREAMER_TYPE_PICKUP, pickupID, E_STREAMER_Z, posZ);
}