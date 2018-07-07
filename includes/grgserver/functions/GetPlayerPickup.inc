GetPlayerPickup(playerID)
{
    Count(pickupID, MAX_PICKUPS)
    {
        if (IsPlayerInRangeOfPoint(playerID, 1.3, g_pickups[pickupID][E_PICKUP_POSX], g_pickups[pickupID][E_PICKUP_POSY], g_pickups[pickupID][E_PICKUP_POSZ]))
        {
            return pickupID;
        }
    }

    return -1;
}