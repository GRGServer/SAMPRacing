forward OnPlayerHiddenPackagesLoaded(playerID);
public OnPlayerHiddenPackagesLoaded(playerID)
{
	Count(row, cache_get_row_count())
	{
		new packageID = cache_get_field_content_int(row, "packageId");
		if (packageID >= 0 && packageID < MAX_HIDDENPACKAGES)
		{
			PVar:playerID[HIDDENPACKAGES][packageID] = true;
		}
	}
}