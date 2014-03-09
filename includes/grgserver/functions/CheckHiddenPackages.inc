CheckHiddenPackages(playerID)
{
	new found;
	new foundCount;
	Foreach(hiddenPackageID, g_hiddenPackages)
	{
		if (PVar:playerID[HIDDENPACKAGES][hiddenPackageID])
		{
			if (IsPlayerInRangeOfPoint(playerID, 1, g_hiddenPackages[hiddenPackageID][E_HIDDENPACKAGE_POSX], g_hiddenPackages[hiddenPackageID][E_HIDDENPACKAGE_POSY], g_hiddenPackages[hiddenPackageID][E_HIDDENPACKAGE_POSZ]))
			{
				// Remove the object
				DestroyDynamicObject(PVar:playerID[HIDDENPACKAGES][hiddenPackageID]);
				PVar:playerID[HIDDENPACKAGES][hiddenPackageID] = 0;

				// Save the state
				MySQLFormat("INSERT INTO `hiddenpackages` (`userId`, `packageId`) VALUES(%d, %d)", PVar:playerID[USERID], hiddenPackageID);
				mysql_pquery(1, g_sqlQuery);

				// One more hidden package
				found = true;
				foundCount++;
			}
		}
		else
		{
			foundCount++;// Object ID = 0 means the player already found the hidden package
		}
	}

	// The player just found a hidden package
	if (found)
	{
		PlaySound(playerID, SOUND_HIDDENPACKAGE);

		GiveHiddenPackagesRewards(playerID, foundCount, true);

		// The player found all hidden packages
		if (foundCount == g_hiddenPackagesCount)
		{
			GameTextForPlayer(playerID, LanguageString(playerID, StringID:97("You found all hidden packages!")), 3000, 3);
		}
		else
		{
			FormatNew:message[100](LanguageString(playerID, StringID:98("Hidden Package %d of %d")), foundCount, g_hiddenPackagesCount);
			GameTextForPlayer(playerID, message, 3000, 3);
		}
	}
}