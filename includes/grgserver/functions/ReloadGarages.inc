ReloadGarages()
{
	print("Loading garages...");

	Foreach(index, g_garages)
	{
		Foreach(field, g_garages[])
		{
			g_garages[index][E_GARAGE:field] = 0;
		}
	}

	DestroyPickupsOfType(PICKUPTYPE_GARAGE_BOUGHT);
	DestroyPickupsOfType(PICKUPTYPE_GARAGE_FREE);

	new garageNumber;
	new XMLNode:xml = XML_LoadDocument("garages.xml");
	xml = XML_GetFirstChild(xml, "garages");
	new XMLNode:garageNode = XML_GetFirstChild(xml, "garage");
	while (garageNode)
	{
		if (garageNumber >= MAX_GARAGES)
		{
			printf("  Reached limit of %d garages", MAX_GARAGES);
			break;
		}

		new garageID = XML_GetIntAttribute(garageNode, "id");

		new XMLNode:vehicleNode = XML_GetFirstChild(garageNode, "vehicle");
		if (!vehicleNode)
		{
			printf("  No vehicle position specified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}

		new XMLNode:cameraNode = XML_GetFirstChild(garageNode, "camera");
		if (!cameraNode)
		{
			printf("  No camera position spedified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}

		new XMLNode:pickupNode = XML_GetFirstChild(garageNode, "pickup");
		if (!pickupNode)
		{
			printf("  No pickup specified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}

		new XMLNode:doorObjectNode = XML_GetFirstChild(garageNode, "doorobject");
		if (doorObjectNode)
		{
			new string[10];
			XML_GetValue(XML_GetFirstChild(doorObjectNode), string);
			g_garages[garageNumber][E_GARAGE_DOOROBJECTID] = strval(string);
			new objectID = GetObjectByID(g_garages[garageNumber][E_GARAGE_DOOROBJECTID]);
			if (objectID != -1)
			{
				g_objects[objectID][E_OBJECT_TYPE] = OBJECTTYPE_GARAGEDOOR;
			}
		}

		g_garages[garageNumber][E_GARAGE_VEHICLE_POSX] = XML_GetFloatAttribute(vehicleNode, "x");
		g_garages[garageNumber][E_GARAGE_VEHICLE_POSY] = XML_GetFloatAttribute(vehicleNode, "y");
		g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ] = XML_GetFloatAttribute(vehicleNode, "z");
		g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE] = XML_GetFloatAttribute(vehicleNode, "angle");

		g_garages[garageNumber][E_GARAGE_CAMERA_POSX] = XML_GetFloatAttribute(cameraNode, "x");
		g_garages[garageNumber][E_GARAGE_CAMERA_POSY] = XML_GetFloatAttribute(cameraNode, "y");
		g_garages[garageNumber][E_GARAGE_CAMERA_POSZ] = XML_GetFloatAttribute(cameraNode, "z");

		g_garages[garageNumber][E_GARAGE_PICKUP_POSX] = XML_GetFloatAttribute(pickupNode, "x");
		g_garages[garageNumber][E_GARAGE_PICKUP_POSY] = XML_GetFloatAttribute(pickupNode, "y");
		g_garages[garageNumber][E_GARAGE_PICKUP_POSZ] = XML_GetFloatAttribute(pickupNode, "z");

		g_garages[garageNumber][E_GARAGE_ID] = garageID;
		g_garages[garageNumber][E_GARAGE_PRICE] = XML_GetIntAttribute(garageNode, "price");
		g_garages[garageNumber][E_GARAGE_ENTERRANGE] = XML_GetIntAttribute(garageNode, "enterrange");

		MySQLFormat("SELECT `userId`, `price` FROM `garages` WHERE `id` = %d", g_garages[garageNumber][E_GARAGE_ID]);
		new Cache:result = mysql_query(1, g_sqlQuery);
		if (cache_get_row_count())
		{
			g_garages[garageNumber][E_GARAGE_USERID] = cache_get_field_content_int(0, "userId");
			g_garages[garageNumber][E_GARAGE_PRICE] = cache_get_field_content_int(0, "price");
		}
		cache_delete(result);

		UpdateGarage(garageNumber);

		garageNumber++;

		garageNode = XML_GetNextSibling(garageNode, "garage");
	}
	XML_UnloadDocument(xml);

	printf("  %d garages loaded", garageNumber);
}