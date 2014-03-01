ACMD:addhp(playerID, params[], StringID:116("Add a hidden package"))
{
	new Float:posX;
	new Float:posY;
	new Float:posZ;
	GetPlayerPos(playerID, posX, posY, posZ);

	if (g_hiddenPackagesCount == MAX_HIDDENPACKAGES)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:117("Limit of %d hidden packages reached!"), MAX_HIDDENPACKAGES);
		return COMMAND_ERROR;
	}

	if (!AddPickup(PICKUPTYPE_HIDDENPACKAGE, posX, posY, posZ, g_hiddenPackagesCount))
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:118("Can not add hidden package!"));
		return COMMAND_ERROR;
	}

	g_hiddenPackagesCount++;

	SaveHiddenPackages();

	SendClientMessageEx(playerID, COLOR_INFO, StringID:119("Hidden package %d added"), g_hiddenPackagesCount);

	return COMMAND_OK;
}