public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    PickupEvent(playerid, pickupid, PICKUPEVENT_PICKUP);

    return true;
}