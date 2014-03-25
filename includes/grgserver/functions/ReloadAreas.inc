ReloadAreas()
{
	print("Loading areas...");

	Foreach(index, g_areas)
	{
		if (IsValidDynamicArea(g_areas[index][E_AREA_ID]))
		{
			DestroyDynamicArea(g_areas[index][E_AREA_ID]);
		}

		Foreach(field, g_areas[])
		{
			g_areas[index][E_AREA:field] = 0;
		}
	}

	new areaID = 0;
	new XMLNode:xml = XML_LoadDocument("areas.xml");
	xml = XML_GetFirstChild(xml, "areas");
	new XMLNode:areaNode = XML_GetFirstChild(xml, "area");
	while (areaNode)
	{
		new XMLNode:node;
		new value[100];

		if (areaID >= MAX_AREAS)
		{
			printf("  Reached limit of %d areas", MAX_AREAS);
			break;
		}

		XML_GetAttribute(areaNode, "type", value);
		if (!strcmp(value, "drift", true))
		{
			g_areas[areaID][E_AREA_TYPE] = AREATYPE_DRIFT;
		}
		else if (!strcmp(value, "stunt", true))
		{
			g_areas[areaID][E_AREA_TYPE] = AREATYPE_STUNT;
		}
		else
		{
			printf("  Invalid area group '%s' for area %d", value, areaID);
			areaNode = XML_GetNextSibling(areaNode, "area");
			continue;
		}

		XML_GetAttribute(areaNode, "name", g_areas[areaID][E_AREA_NAME], STRINGLENGTH_AREANAME);

		node = XML_GetFirstChild(areaNode, "minz");
		new Float:minZ = -FLOAT_INFINITY;
		if (node)
		{
			minZ = XML_GetFloatValue(node);
		}

		node = XML_GetFirstChild(areaNode, "maxz");
		new Float:maxZ = FLOAT_INFINITY;
		if (node)
		{
			maxZ = XML_GetFloatValue(node);
		}

		new Float:points[MAX_AREAPOINTS * 2];
		new pointIndex;

		node = XML_GetFirstChild(areaNode, "point");
		if (!node)
		{
			printf("  Node 'point' missing for area %d", areaID);
			areaNode = XML_GetNextSibling(areaNode, "area");
			continue;
		}
		while (node)
		{
			if (pointIndex >= MAX_AREAPOINTS * 2)
			{
				printf("  Reached limit of %d polygon points", MAX_AREAPOINTS);
				break;
			}

			XML_GetAttribute(node, "x", value);
			points[pointIndex] = floatstr(value);
			pointIndex++;

			XML_GetAttribute(node, "y", value);
			points[pointIndex] = floatstr(value);
			pointIndex++;

			node = XML_GetNextSibling(node, "point");
		}

		g_areas[areaID][E_AREA_ID] = CreateDynamicPolygon(points, minZ, maxZ, pointIndex);

		Streamer_SetIntData(STREAMER_TYPE_AREA, g_areas[areaID][E_AREA_ID], E_STREAMER_EXTRA_ID, areaID);

		areaID++;

		areaNode = XML_GetNextSibling(areaNode, "area");
	}
	XML_UnloadDocument(xml);

	printf("  %d areas loaded", areaID);
}