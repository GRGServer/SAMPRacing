PickupEvent(playerID, pickupID, eventType)
{
	FormatNew:functionName[MAX_FUNCTION_NAME]("PUE_%s", g_pickups[pickupID][E_PICKUP_TYPE]);// PUE = PickUpEvent
	if (funcidx(functionName) == -1)
	{
		printf("Unknown pickup type: %s", g_pickups[pickupID][E_PICKUP_TYPE]);
		return false;
	}

	if (!CallLocalFunction(functionName, "ddd", playerID, pickupID, eventType))
	{
		return false;
	}

	PlaySound(playerID, SOUND_PICKUPEVENT);
	return true;
}