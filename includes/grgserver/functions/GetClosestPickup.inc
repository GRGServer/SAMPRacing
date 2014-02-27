GetClosestPickup(Float:posX, Float:posY, Float:posZ, type, &Float:distance = 0.0)
{
	new pickupID;
	distance = 6000.0;

	Count(checkPickupID, MAX_PICKUPS)
	{
		if (g_pickups[checkPickupID][E_PICKUP_TYPE] == type)
		{
			new Float:checkDistance = GetDistanceBetweenPoints(posX, posY, posZ, g_pickups[checkPickupID][E_PICKUP_POSX], g_pickups[checkPickupID][E_PICKUP_POSY], g_pickups[checkPickupID][E_PICKUP_POSZ]);
			if (checkDistance < distance)
			{
				distance = checkDistance;
				pickupID = checkPickupID;
			}
		}
	}

	return pickupID;
}