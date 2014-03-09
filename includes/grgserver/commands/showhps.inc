PCMD:showhps[ISADMIN](playerID, params[], StringID:114("Show all hidden packages on the map"))
{
	Count(iconIndex, 100)
	{
		RemovePlayerMapIcon(playerID, iconIndex);
	}

	new iconID;
	Foreach(packageID, g_hiddenPackages)
	{
		if (iconID >= 100)
		{
			break;
		}

		new iconType;
		if (PVar:playerID[HIDDENPACKAGES][packageID])
		{
			iconType = 52;
		}
		else
		{
			iconType = 36;
		}

		SetPlayerMapIcon(playerID, iconID, g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY], g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ], iconType, 0, MAPICON_GLOBAL);
		iconID++;
	}

	SendClientMessageEx(playerID, COLOR_INFO, StringID:115("The hidden packages have been marked on your map"));
	return COMMAND_OK;
}