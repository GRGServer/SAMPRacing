PickupEvent(playerID, pickupID, eventType)
{
	new linkID = g_pickups[pickupID][E_PICKUP_LINKID];

	switch (g_pickups[pickupID][E_PICKUP_TYPE])
	{
		case PICKUPTYPE_HOSPITAL:
		{
			SetPlayerHealth(playerID, 100);
		}
		case PICKUPTYPE_VEHICLESHOP:
		{
			EnterVehicleShop(playerID, linkID, false);
		}
	}

	PlaySound(playerID, SOUND_PICKUPEVENT);
	return true;
}