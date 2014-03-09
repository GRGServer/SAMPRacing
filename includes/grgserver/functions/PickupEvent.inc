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

				MySQLFormat("INSERT INTO `hiddenpackages` (`userId`, `packageId`) VALUES(%d, %d)", PVar:playerID[USERID], linkID);
				mysql_pquery(1, g_sqlQuery);

				switch (hiddenPackagesFound)
				{
					case 10:
					{
						new money = 15000;
						SendClientMessageEx(playerID, COLOR_INFO, StringID:128("You got $%d for finding 10 hidden packages"), money);
						GivePlayerMoney(playerID, money);
						SavePlayer(playerID);
					}
					case 20:
					{
						// TODO: Give something to the player
					}
					case 30:
					{
						// TODO: Give something to the player
					}
					case 40:
					{
						// TODO: Give something to the player
					}
					case 50:
					{
						PVar:playerID[HAS_MOBILEVEHICLESHOP] = true;
						SavePlayer(playerID);

						SendClientMessageEx(playerID, COLOR_INFO, StringID:129("You now own the mobile vehicle shop"));
						SendClientMessageEx(playerID, COLOR_INFO, StringID:130("It allows you to buy a vehicle wherever you are"));
						SendClientMessageEx(playerID, COLOR_INFO, StringID:131("Just enable it using /mobilevehicleshop or /mvs"));
					}
					case 60:
					{
						// TODO: Give something to the player
					}
					case 70:
					{
						// TODO: Give something to the player
					}
					case 80:
					{
						// TODO: Give something to the player
					}
					case 90:
					{
						// TODO: Give something to the player
					}
					case 100:
					{
						// TODO: Give something to the player
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