PickupEvent(playerID, pickupID, eventType)
{
	switch (g_pickups[pickupID][E_PICKUP_TYPE])
	{
		case PICKUPTYPE_HOSPITAL:
		{
			SetPlayerHealth(playerID, 100);
		}
		case PICKUPTYPE_VEHICLESHOP:
		{
			EnterVehicleShop(playerID, g_pickups[pickupID][E_PICKUP_LINKID], false);
		}
	}

	PlaySound(playerID, SOUND_PICKUPEVENT);
	return true;
}