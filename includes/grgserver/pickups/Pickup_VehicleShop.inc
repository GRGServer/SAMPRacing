PickupEvent:VehicleShop(playerID, pickupID, eventType)
{
	if (eventType == PICKUPEVENT_PICKUP)
	{
		PVar:playerID[VEHICLESHOP_PICKUPID] = pickupID;
		EnterVehicleShop(playerID);

		return true;
	}

	return false;
}

PickupModelID:VehicleShop()
{
	return 1274;
}