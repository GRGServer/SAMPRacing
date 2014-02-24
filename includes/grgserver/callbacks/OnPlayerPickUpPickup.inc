public OnPlayerPickUpPickup(playerid, pickupid)
{
	new streamerPickupID = Streamer_GetItemStreamerID(playerid, STREAMER_TYPE_PICKUP, pickupid);
	new pickupID = Streamer_GetIntData(STREAMER_TYPE_PICKUP, streamerPickupID, E_STREAMER_EXTRA_ID);

	PickupEvent(playerid, pickupID, PICKUPEVENT_PICKUP);
	return true;
}