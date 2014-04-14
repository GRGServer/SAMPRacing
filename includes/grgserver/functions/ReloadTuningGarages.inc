ReloadTuningGarages()
{
	print("Loading tuning garages...");

	Foreach(index, g_tuningGarages)
	{
		Foreach(field, g_tuningGarages[])
		{
			g_tuningGarages[index][E_TUNINGGARAGE:field] = 0;
		}
	}

	new tuningGarageNumber;
	new XMLNode:xml = XML_LoadDocument("tuninggarages.xml");
	xml = XML_GetFirstChild(xml, "tuninggarages");
	new XMLNode:tuningGarageNode = XML_GetFirstChild(xml, "tuninggarage");
	while (tuningGarageNode)
	{
		if (tuningGarageNumber >= MAX_TUNINGGARAGES)
		{
			printf("  Reached limit of %d tuning garages", MAX_TUNINGGARAGES);
			break;
		}

		new tuningGarageID = XML_GetIntAttribute(tuningGarageNode, "id");

		new XMLNode:vehicleNode = XML_GetFirstChild(tuningGarageNode, "vehicle");
		if (!vehicleNode)
		{
			printf("  No vehicle position specified for tuning garage %d", tuningGarageID);
			tuningGarageNode = XML_GetNextSibling(tuningGarageNode, "tuninggarage");
			continue;
		}

		new XMLNode:cameraNode = XML_GetFirstChild(tuningGarageNode, "camera");
		if (!cameraNode)
		{
			printf("  No camera position spedified for tuning garage %d", tuningGarageID);
			tuningGarageNode = XML_GetNextSibling(tuningGarageNode, "tuninggarage");
			continue;
		}

		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX] = XML_GetFloatAttribute(vehicleNode, "x");
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY] = XML_GetFloatAttribute(vehicleNode, "y");
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ] = XML_GetFloatAttribute(vehicleNode, "z");
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_ANGLE] = XML_GetFloatAttribute(vehicleNode, "angle");

		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSX] = XML_GetFloatAttribute(cameraNode, "x");
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSY] = XML_GetFloatAttribute(cameraNode, "y");
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSZ] = XML_GetFloatAttribute(cameraNode, "z");

		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ID] = tuningGarageID;
		g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ENTERRANGE] = XML_GetIntAttribute(tuningGarageNode, "enterrange");

		tuningGarageNumber++;

		tuningGarageNode = XML_GetNextSibling(tuningGarageNode, "tuninggarage");
	}
	XML_UnloadDocument(xml);

	printf("  %d tuning garages loaded", tuningGarageNumber);
}