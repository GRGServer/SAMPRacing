ACMD:reload(playerID, params[], StringID:55("Reload parts of the script"))
{
	new part[100];
	if (sscanf(params, "s[100]", part))
	{
		CmdUsageMsg(playerID, "reload", "Part");
		SendClientMessageEx(playerID, COLOR_INFO, StringID:56("Available parts: %s"), "areas, commandaliases, languagestrings, pickups, teleports, vehiclemodels");
		return COMMAND_USAGE;
	}

	if (!strcmp(part, "areas", true))
	{
		ReloadAreas();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:72("Areas reloaded"));
		return COMMAND_OK;
	}

	if (!strcmp(part, "commandaliases", true))
	{
		ReloadCommandAliases();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:44("Command aliases reloaded"));
		return COMMAND_OK;
	}

	if (!strcmp(part, "languagestrings", true))
	{
		ReloadLanguageStrings();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:57("Language strings reloaded"));
		return COMMAND_OK;
	}

	if (!strcmp(part, "pickups", true))
	{
		ReloadPickups();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:77("Pickups reloaded"));
		return COMMAND_OK;
	}

	if (!strcmp(part, "teleports", true))
	{
		ReloadTeleports();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:58("Teleports reloaded"));
		return COMMAND_OK;
	}

	if (!strcmp(part, "vehiclemodels", true))
	{
		ReloadVehicleModels();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:59("Vehicle models reloaded"));
		return COMMAND_OK;
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:60("Invalid part name!"));
	return COMMAND_ERROR;
}