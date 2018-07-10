GetClosestPickup(Float:posX, Float:posY, Float:posZ, type, &Float:distance = 0.0)
{
    new pickupID;
    distance = 6000.0;

    Count(checkPickupID, MAX_DYNAMIC_PICKUPS)
    {
        if (g_pickups[checkPickupID][E_PICKUP_TYPE] == type)
        {
            new Float:checkDistance;
            Streamer_GetDistanceToItem(posX, posY, posZ, STREAMER_TYPE_PICKUP, checkPickupID, checkDistance);
            if (checkDistance < distance)
            {
                distance = checkDistance;
                pickupID = checkPickupID;
            }
        }
    }

    return pickupID;
}