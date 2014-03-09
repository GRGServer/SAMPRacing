forward OnPlayerHiddenPackagesLoaded(playerID);
public OnPlayerHiddenPackagesLoaded(playerID)
{
	new hiddenPackagesFound;
	Count(row, cache_get_row_count())
	{
		new packageID = cache_get_field_content_int(row, "packageId");
		if (packageID >= 0 && packageID < MAX_HIDDENPACKAGES)
		{
			PVar:playerID[HIDDENPACKAGES][packageID] = true;
			hiddenPackagesFound++;
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