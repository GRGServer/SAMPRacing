DestroyPickupsOfType(type)
{
    Foreach(pickupID, g_pickups)
    {
        if (g_pickups[pickupID][E_PICKUP_TYPE] == type)
        {
            DestroyPickup(pickupID);

            Foreach(field, g_pickups[])
            {
                g_pickups[pickupID][E_PICKUP:field] = 0;
            }
        }
    }
}