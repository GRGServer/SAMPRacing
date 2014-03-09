GiveHiddenPackagesRewards(playerID, foundCount, foundNow)
{
	// 10 hidden packages have been found now
	if (foundCount == 10 && foundNow)
	{
		new money = 15000;
		SendClientMessageEx(playerID, COLOR_INFO, StringID:128("You got $%d for finding 10 hidden packages"), money);
		GivePlayerMoney(playerID, money);
		SavePlayer(playerID);
	}

	// 50 or more hidden packages have been found
	if (foundCount >= 50)
	{
		PVar:playerID[HAS_MOBILEVEHICLESHOP] = true;

		// 50 hidden packages have been found now
		if (foundCount == 50 && foundNow)
		{
			SavePlayer(playerID);

			SendClientMessageEx(playerID, COLOR_INFO, StringID:129("You now own the mobile vehicle shop"));
			SendClientMessageEx(playerID, COLOR_INFO, StringID:130("It allows you to buy a vehicle wherever you are"));
			SendClientMessageEx(playerID, COLOR_INFO, StringID:131("Just enable it using /mobilevehicleshop or /mvs"));
		}
	}
}