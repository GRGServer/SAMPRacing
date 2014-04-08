ReloadVehicleModels()
{
	print("Loading vehicle models...");

	Foreach(index, g_vehicleModels)
	{
		Foreach(field, g_vehicleModels[])
		{
			g_vehicleModels[index][E_VEHICLEMODEL:field] = 0;
		}
	}

	new count;
	new XMLNode:xml = XML_LoadDocument("vehiclemodels.xml");
	xml = XML_GetFirstChild(xml, "vehiclemodels");
	new XMLNode:modelNode = XML_GetFirstChild(xml, "model");
	while (modelNode)
	{
		new modelID = XML_GetIntAttribute(modelNode, "id");
		if (modelID < 400 || modelID > 611)
		{
			printf("Invalid vehicle model ID: %d", modelID);
			modelNode = XML_GetNextSibling(modelNode, "model");
			continue;
		}

		new arrayIndex = modelID - 400;// First array element starts with 0, vehicle models are starting with 400 (400 - 400 = 0, 401 - 400 = 1, ...)

		XML_GetAttribute(modelNode, "name", g_vehicleModels[arrayIndex][E_VEHICLEMODEL_NAME], STRINGLENGTH_VEHICLENAME);
		XML_GetAttribute(modelNode, "type", g_vehicleModels[arrayIndex][E_VEHICLEMODEL_TYPE], STRINGLENGTH_VEHICLETYPE);

		g_vehicleModels[arrayIndex][E_VEHICLEMODEL_PRICE] = XML_GetIntAttribute(modelNode, "price");

		count++;

		modelNode = XML_GetNextSibling(modelNode, "model");
	}
	XML_UnloadDocument(xml);

	printf("  %d vehicle models loaded", count);
}