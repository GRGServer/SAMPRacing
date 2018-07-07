public OnPlayerPickUpPickup(playerid, pickupid)
{
    PickupEvent(playerid, pickupid, PICKUPEVENT_PICKUP);

    return true;
}