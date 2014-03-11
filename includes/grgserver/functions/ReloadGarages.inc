ReloadGarages()
{
	print("Loading garages...");

	Foreach(index, g_garages)
	{
		if (IsValidDynamicCP(g_garages[index][E_GARAGE_CHECKPOINT_ID]))
		{
			DestroyDynamicCP(g_garages[index][E_GARAGE_CHECKPOINT_ID]);
		}

		Foreach(field, g_garages[])
		{
			g_garages[index][E_GARAGE:field] = 0;
		}

		g_garages[index][E_GARAGE_PICKUP_ID] = -1;
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

		new type[10];
		XML_GetAttribute(garageNode, "type", type);
		if (IsStr(type, "small"))
		{
			g_garages[garageNumber][E_GARAGE_TYPE] = GARAGE_SMALL;
		}
		else if (IsStr(type, "large"))
		{
			g_garages[garageNumber][E_GARAGE_TYPE] = GARAGE_LARGE;
		}
		else
		{
			printf("  Invalid garage type specified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}

		new XMLNode:checkpointNode = XML_GetFirstChild(garageNode, "checkpoint");
		if (!checkpointNode)
		{
			printf("  No checkpoint specified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}
		g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSX] = XML_GetFloatAttribute(checkpointNode, "x");
		g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSY] = XML_GetFloatAttribute(checkpointNode, "y");
		g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSZ] = XML_GetFloatAttribute(checkpointNode, "z");

		new XMLNode:pickupNode = XML_GetFirstChild(garageNode, "pickup");
		if (!pickupNode)
		{
			printf("  No pickup specified for garage %d", garageID);
			garageNode = XML_GetNextSibling(garageNode, "garage");
			continue;
		}
		g_garages[garageNumber][E_GARAGE_PICKUP_POSX] = XML_GetFloatAttribute(pickupNode, "x");
		g_garages[garageNumber][E_GARAGE_PICKUP_POSY] = XML_GetFloatAttribute(pickupNode, "y");
		g_garages[garageNumber][E_GARAGE_PICKUP_POSZ] = XML_GetFloatAttribute(pickupNode, "z");

		g_garages[garageNumber][E_GARAGE_ID] = garageID;
		g_garages[garageNumber][E_GARAGE_PRICE] = XML_GetIntAttribute(garageNode, "price");

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

	printf("  %d garages loaded", garageNumber);
}