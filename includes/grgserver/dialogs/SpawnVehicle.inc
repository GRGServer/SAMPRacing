// Dialog is created at another location (e.g. ACMD:spawnvehicle)

DialogResponse:SpawnVehicle(playerID, response, listItem, inputText[])
{
	if (response)
	{
		new modelID;
		new name[STRINGLENGTH_VEHICLENAME];
		if (!sscanf(inputText, "p<\t>ds[" #STRINGLENGTH_VEHICLENAME "]", modelID, name))
		{
			if (modelID)
			{
				SpawnVehicle(playerID, modelID, -1, -1, true);
			}
		}
	}
}