forward OnPlayerHiddenPackagesLoaded(playerID);
public OnPlayerHiddenPackagesLoaded(playerID)
{
    new hiddenPackagesFound;
    new foundHiddenPackages[MAX_HIDDENPACKAGES];
    new rows;
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new packageID;
        cache_get_value_int(row, "packageId", packageID);
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
    GiveHiddenPackagesRewards(playerID, hiddenPackagesFound, false);

    if (hiddenPackagesFound < g_hiddenPackagesCount)
    {
        SendClientMessageEx(playerID, COLOR_INFO, StringID:132("You found %d of %d hidden packages"), hiddenPackagesFound, g_hiddenPackagesCount);
    }
}