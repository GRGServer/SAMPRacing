PickupEvent(playerID, pickupID, eventType)
{
	new linkID = g_pickups[pickupID][E_PICKUP_LINKID];

	switch (g_pickups[pickupID][E_PICKUP_TYPE])
	{
		case PICKUPTYPE_GARAGE_BOUGHT:
		{
			// TODO
		}
		case PICKUPTYPE_GARAGE_FREE:
		{
			switch (eventType)
			{
				case PICKUPEVENT_KEY:
				{
					if (GetPlayerMoney(playerID) < g_garages[linkID][E_GARAGE_PRICE])
					{
						GameTextForPlayer(playerID, LanguageString(playerID, StringID:80("You do not have enough money!")), 3000, 3);
					}
					else
					{
						ShowDialog:ConfirmGarageBuy(playerID);
					}
				}
				case PICKUPEVENT_PICKUP:
				{
					SendClientMessageEx(playerID, COLOR_INFO, StringID:134("Press %s to use this pickup"), GetGameTextKeyByID(KEY_PICKUP_USE, false));
				}
			}
		}
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