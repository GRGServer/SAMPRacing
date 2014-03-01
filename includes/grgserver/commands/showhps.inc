ACMD:showhps(playerID, params[], StringID:114("Show all hidden packages on the map"))
{
	Count(iconIndex, 100)
	{
		RemovePlayerMapIcon(playerID, iconIndex);
	}

	new iconID;
	Count(pickupID, MAX_PICKUPS)
	{
		if (iconID >= 100)
		{
			break;
		}

		if (g_pickups[pickupID][E_PICKUP_TYPE] == PICKUPTYPE_HIDDENPACKAGE)
		{
			SetPlayerMapIcon(playerID, iconID, g_pickups[pickupID][E_PICKUP_POSX], g_pickups[pickupID][E_PICKUP_POSY], g_pickups[pickupID][E_PICKUP_POSZ], 56, 0, MAPICON_GLOBAL);
			iconID++;
		}
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:115("The hidden packages have been marked on your map"));
	return COMMAND_OK;
}