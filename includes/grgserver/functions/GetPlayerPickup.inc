GetPlayerPickup(playerID)
{
    Count(pickupID, MAX_DYNAMIC_PICKUPS)
    {
        new Float:posX;
        new Float:posY;
        new Float:posZ;
        GetDynamicPickupPos(pickupID, posX, posY, posZ);
        if (IsPlayerInRangeOfPoint(playerID, 1.3, posX, posY, posZ))
        {
            return pickupID;
        }
    }

    return -1;
}