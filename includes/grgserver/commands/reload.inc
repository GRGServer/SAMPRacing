PCMD:reload[ISADMIN](playerID, params[], StringID:55("Reload parts of the script"))
{
	new part[100];
	if (sscanf(params, "s[100]", part))
	{
		CmdUsageMsg(playerID, "reload", "Part");
		SendClientMessageEx(playerID, COLOR_INFO, StringID:56("Available parts:"));
		SendClientMessage(playerID, COLOR_INFO, "areas, commandaliases, garages, interiors, languagestrings, objectmodels");
		SendClientMessage(playerID, COLOR_INFO, "objects, pickups, races, teleports, vehiclemodels, vehicles, vehicleshops");
		return COMMAND_USAGE;
	}

	if (IsStr(part, "areas"))
	{
		ReloadAreas();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:72("Areas reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "commandaliases"))
	{
		ReloadCommandAliases();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:44("Command aliases reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "garages"))
	{
		ReloadGarages();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:141("Garages reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "interiors"))
	{
		ReloadInteriors();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:142("Interiors reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "languagestrings"))
	{
		ReloadLanguageStrings();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:57("Language strings reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "objectmodels"))
	{
		ReloadObjectModels();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:105("Object models reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "objects"))
	{
		ReloadObjects();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:106("Objects reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "pickups"))
	{
		ReloadPickups();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:77("Pickups reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "races"))
	{
		ReloadRaces();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:155("Races reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "teleports"))
	{
		ReloadTeleports();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:58("Teleports reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "vehiclemodels"))
	{
		ReloadVehicleModels();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:59("Vehicle models reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "vehicles"))
	{
		ReloadVehicles();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:88("Vehicles reloaded"));
		return COMMAND_OK;
	}

	if (IsStr(part, "vehicleshops"))
	{
		ReloadVehicleShops();
		SendClientMessageEx(playerID, COLOR_INFO, StringID:89("Vehicle shops reloaded"));
		return COMMAND_OK;
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:60("Invalid part name!"));
	return COMMAND_ERROR;
}