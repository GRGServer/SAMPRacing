PickupEvent:Hospital(playerID, pickupID, eventType)
{
	SetPlayerHealth(playerID, 100);
	return true;
}

PickupModelID:Hospital()
{
	return 1240;
}