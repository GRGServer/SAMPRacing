PickupEvent(playerID, pickupID, eventType)
{
	new linkID = g_pickups[pickupID][E_PICKUP_LINKID];

	switch (g_pickups[pickupID][E_PICKUP_TYPE])
	{
		case PICKUPTYPE_HIDDENPACKAGE:
		{
			if (PVar:playerID[HIDDENPACKAGES][linkID])
			{
				GameTextForPlayer(playerID, LanguageString(playerID, StringID:96("You already found this hidden package!")), 3000, 3);
			}
			else
			{
				PVar:playerID[HIDDENPACKAGES][linkID] = true;

				new hiddenPackagesFound = 0;
				Count(packageID, MAX_HIDDENPACKAGES)
				{
					if (PVar:playerID[HIDDENPACKAGES][packageID])
					{
						hiddenPackagesFound++;
					}
				}

				if (hiddenPackagesFound == g_hiddenPackagesCount)
				{
					GameTextForPlayer(playerID, LanguageString(playerID, StringID:97("You found all hidden packages!")), 3000, 3);
				}
				else
				{
					FormatNew:message[100](LanguageString(playerID, StringID:98("Hidden Package %d of %d")), hiddenPackagesFound, g_hiddenPackagesCount);
					GameTextForPlayer(playerID, message, 3000, 3);
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