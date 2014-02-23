ReloadVehicleModels()
{
	print("Loading vehicle models...");
	new count;
	new XMLNode:xml = XML_LoadDocument("vehiclemodels.xml");
	xml = XML_GetFirstChild(xml, "vehiclemodels");
	new XMLNode:modelNode = XML_GetFirstChild(xml, "model");
	while (modelNode)
	{
		new idString[10];
		XML_GetValue(XML_GetFirstChild(XML_GetFirstChild(modelNode, "id")), idString);
		new modelID = strval(idString);

		if (modelID >= 400 && modelID <= 611)
		{
			new arrayIndex = modelID - 400;// First array element starts with 0, vehicle models are starting with 400 (400 - 400 = 0, 401 - 400 = 1, ...)

			XML_GetValue(XML_GetFirstChild(XML_GetFirstChild(modelNode, "name")), g_vehicleModels[arrayIndex][E_VEHICLEMODEL_NAME], STRINGLENGTH_VEHICLENAME);

			XML_GetValue(XML_GetFirstChild(XML_GetFirstChild(modelNode, "type")), g_vehicleModels[arrayIndex][E_VEHICLEMODEL_TYPE], STRINGLENGTH_VEHICLETYPE);

			new priceString[20];
			XML_GetValue(XML_GetFirstChild(XML_GetFirstChild(modelNode, "price")), priceString);
			g_vehicleModels[arrayIndex][E_VEHICLEMODEL_PRICE] = strval(priceString);

			count++;
		}
		else
		{
			printf("Invalid vehicle model ID: %d", modelID);
		}

		modelNode = XML_GetNextSibling(modelNode, "model");
	}
	printf("  %d vehicle models loaded", count);
}