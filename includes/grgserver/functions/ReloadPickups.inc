ReloadPickups()
{
	print("Loading pickups...");

	Foreach(index, g_pickups)
	{
		if (IsValidDynamicPickup(g_pickups[index][E_PICKUP_ID]))
		{
			DestroyDynamicPickup(g_pickups[index][E_PICKUP_ID]);
		}

		Foreach(field, g_pickups[])
		{
			g_pickups[index][E_PICKUP:field] = 0;
		}
	}

	new pickupID = 0;
	new XMLNode:xml = XML_LoadDocument("pickups.xml");
	xml = XML_GetFirstChild(xml, "pickups");
	new XMLNode:pickupNode = XML_GetFirstChild(xml, "pickup");
	while (pickupNode)
	{
		if (pickupID >= MAX_PICKUPS)
		{
			printf("  Reached limit of %d pickups", MAX_PICKUPS);
			break;
		}

		new value[100];
		XML_GetAttribute(pickupNode, "type", value);
		FormatNew:functionName[MAX_FUNCTION_NAME]("PUMID_%s", value);// PUMID = PickUpModelID
		if (funcidx(functionName) == -1)
		{
			printf("  Invalid pickup type '%s' for pickup %d", value, pickupID);
			pickupNode = XML_GetNextSibling(pickupNode, "pickup");
			continue;
		}

		strcat(g_pickups[pickupID][E_PICKUP_TYPE], value, STRINGLENGTH_PICKUPTYPE);
		new modelID = CallLocalFunction(functionName, "");

		new XMLNode:positionNode = XML_GetFirstChild(pickupNode, "position");
		if (!positionNode)
		{
			printf("  Node 'position' missing for pickup %d", pickupID);
			pickupNode = XML_GetNextSibling(pickupNode, "pickup");
			continue;
		}

		new XMLNode:respawnNode = XML_GetFirstChild(pickupNode, "respawn");
		if (respawnNode)
		{
			g_pickups[pickupID][E_PICKUP_RESPAWN_POSX] = XML_GetFloatAttribute(respawnNode, "x");
			g_pickups[pickupID][E_PICKUP_RESPAWN_POSY] = XML_GetFloatAttribute(respawnNode, "y");
			g_pickups[pickupID][E_PICKUP_RESPAWN_POSZ] = XML_GetFloatAttribute(respawnNode, "z");
			g_pickups[pickupID][E_PICKUP_RESPAWN_ANGLE] = XML_GetFloatAttribute(respawnNode, "angle");
		}

		g_pickups[pickupID][E_PICKUP_ID] = CreateDynamicPickup(modelID, 1, XML_GetFloatAttribute(positionNode, "x"), XML_GetFloatAttribute(positionNode, "y"), XML_GetFloatAttribute(positionNode, "z"));

		Streamer_SetIntData(STREAMER_TYPE_PICKUP, g_pickups[pickupID][E_PICKUP_ID], E_STREAMER_EXTRA_ID, pickupID);

		pickupID++;

		pickupNode = XML_GetNextSibling(pickupNode, "pickup");
	}

	printf("  %d pickups loaded", pickupID);
}