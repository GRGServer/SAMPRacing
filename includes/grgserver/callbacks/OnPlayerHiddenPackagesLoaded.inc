forward OnPlayerHiddenPackagesLoaded(playerID);
public OnPlayerHiddenPackagesLoaded(playerID)
{
	new hiddenPackagesFound;
	new foundHiddenPackages[MAX_HIDDENPACKAGES];
	Count(row, cache_get_row_count())
	{
		new packageID = cache_get_field_content_int(row, "packageId");
		if (packageID >= 0 && packageID < MAX_HIDDENPACKAGES)
		{
			foundHiddenPackages[packageID] = true;
			hiddenPackagesFound++;
		}
	}

	Foreach(packageID, foundHiddenPackages)
	{
		if (!foundHiddenPackages[packageID])
		{
			PVar:playerID[HIDDENPACKAGES][packageID] = CreateDynamicObject(1276, g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ], 0, 0, 0, -1, -1, playerID);
		}
	}

	// Restore rewards
	if (hiddenPackagesFound >= 50)
	{
		PVar:playerID[HAS_MOBILEVEHICLESHOP] = true;
	}

	if (hiddenPackagesFound < g_hiddenPackagesCount)
	{
		SendClientMessageEx(playerID, COLOR_INFO, StringID:132("You found %d of %d hidden packages"), hiddenPackagesFound, g_hiddenPackagesCount);
	}
}