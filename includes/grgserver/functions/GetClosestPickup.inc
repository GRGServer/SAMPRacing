GetClosestPickup(Float:posX, Float:posY, Float:posZ, type[], &Float:distance = 0.0)
{
	new pickupID;
	distance = 6000.0;

	Count(checkPickupID, MAX_PICKUPS)
	{
		if (IsStr(g_pickups[checkPickupID][E_PICKUP_TYPE], type))
		{
			new Float:pickupPosX;
			new Float:pickupPosY;
			new Float:pickupPosZ;
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, g_pickups[checkPickupID][E_PICKUP_ID], E_STREAMER_X, pickupPosX);
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, g_pickups[checkPickupID][E_PICKUP_ID], E_STREAMER_Y, pickupPosY);
			Streamer_GetFloatData(STREAMER_TYPE_PICKUP, g_pickups[checkPickupID][E_PICKUP_ID], E_STREAMER_Z, pickupPosZ);

			new Float:checkDistance = GetDistanceBetweenPoints(posX, posY, posZ, pickupPosX, pickupPosY, pickupPosZ);
			if (checkDistance < distance)
			{
				distance = checkDistance;
				pickupID = checkPickupID;
			}
		}
	}

	return pickupID;
}