ACMD:spawnvehicle(playerID, params[], StringID:1("Spawn a vehicle"))
{
	new vehicleName[20];
	new modelID;

	if (sscanf(params, "d", modelID))
	{
		if (sscanf(params, "s[20]", vehicleName))
		{
			CmdUsageMsg(playerID, "spawnvehicle", "ModelID/Name/t:Type", "[Color1]", "[Color2]");
			return COMMAND_USAGE;
		}

		new vehicleList[2048];
		new foundVehicles;

		Foreach(arrayIndex, vehicleModels)
		{
			if (strfind(vehicleModels[arrayIndex][VEHICLEMODEL_NAME], vehicleName, true) != -1)
			{
				AddLine:vehicleList("%d\t%s", arrayIndex + 400, vehicleModels[arrayIndex][VEHICLEMODEL_NAME]);
				foundVehicles++;
				modelID = arrayIndex + 400;
			}
		}

		if (foundVehicles > 1)
		{
			FormatNew:title[64](LanguageString(playerID, StringID:2("Spawn a vehicle [%s]")), vehicleName);
			CreateDialog(playerID, "SpawnVehicle", DIALOG_STYLE_LIST, title, vehicleList, LanguageString(playerID, StringID:3("Spawn")), LanguageString(playerID, StringID:4("Cancel")));

			return COMMAND_OK;
		}
	}

	if (modelID < 400 || modelID > 611)
	{
		return COMMAND_ERROR;
	}

	if (SpawnVehicle(playerID, modelID, -1, -1, true))
	{
		return COMMAND_OK;
	}
	return COMMAND_ERROR;
}