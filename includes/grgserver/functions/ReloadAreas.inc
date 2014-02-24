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

		if (areaID >= MAX_TELEPORTS)
		{
			printf("  Reached limit of %d areas", MAX_AREAS);
			break;
		}

		XML_GetAttribute(areaNode, "group", value);
		if (!strcmp(value, "drift", true))
		{
			g_areas[areaID][E_AREA_GROUP] = AREAGROUP_DRIFT;
		}
		else
		{
			printf("  Invalid area group '%s' for area %d", value, areaID);
			areaNode = XML_GetNextSibling(areaNode, "area");
			continue;
		}

		XML_GetAttribute(areaNode, "name", g_areas[areaID][E_AREA_NAME], STRINGLENGTH_AREANAME);

		XML_GetAttribute(areaNode, "type", value);
		if (!strcmp(value, "circle", true))
		{
			node = XML_GetFirstChild(areaNode, "x");
			if (!node)
			{
				printf("  Node 'x' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:x = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "y");
			if (!node)
			{
				printf("  Node 'y' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:y = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "size");
			if (!node)
			{
				printf("  Node 'size' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:size = XML_GetFloatValue(node);

			g_areas[areaID][E_AREA_TYPE] = STREAMER_AREA_TYPE_CIRCLE;
			g_areas[areaID][E_AREA_ID] = CreateDynamicCircle(x, y, size);
		}
		else if (!strcmp(value, "rectangle", true))
		{
			node = XML_GetFirstChild(areaNode, "minx");
			if (!node)
			{
				printf("  Node 'minx' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:minX = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "miny");
			if (!node)
			{
				printf("  Node 'miny' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:minY = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "maxx");
			if (!node)
			{
				printf("  Node 'maxx' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:maxX = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "maxy");
			if (!node)
			{
				printf("  Node 'maxy' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:maxY = XML_GetFloatValue(node);

			g_areas[areaID][E_AREA_TYPE] = STREAMER_AREA_TYPE_RECTANGLE;
			g_areas[areaID][E_AREA_ID] = CreateDynamicRectangle(minX, minY, maxX, maxY);
		}
		else if (!strcmp(value, "sphere", true))
		{
			node = XML_GetFirstChild(areaNode, "x");
			if (!node)
			{
				printf("  Node 'x' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:x = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "y");
			if (!node)
			{
				printf("  Node 'y' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:y = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "z");
			if (!node)
			{
				printf("  Node 'z' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:z = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "size");
			if (!node)
			{
				printf("  Node 'size' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:size = XML_GetFloatValue(node);

			g_areas[areaID][E_AREA_TYPE] = STREAMER_AREA_TYPE_SPHERE;
			g_areas[areaID][E_AREA_ID] = CreateDynamicSphere(x, y, z, size);
		}
		else if (!strcmp(value, "cube", true))
		{
			node = XML_GetFirstChild(areaNode, "minx");
			if (!node)
			{
				printf("  Node 'minx' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:minX = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "miny");
			if (!node)
			{
				printf("  Node 'miny' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:minY = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "minz");
			if (!node)
			{
				printf("  Node 'minz' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:minZ = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "maxx");
			if (!node)
			{
				printf("  Node 'maxx' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:maxX = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "maxy");
			if (!node)
			{
				printf("  Node 'maxy' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:maxY = XML_GetFloatValue(node);

			node = XML_GetFirstChild(areaNode, "maxz");
			if (!node)
			{
				printf("  Node 'maxz' missing for area %d", areaID);
				areaNode = XML_GetNextSibling(areaNode, "area");
				continue;
			}
			new Float:maxZ = XML_GetFloatValue(node);

			g_areas[areaID][E_AREA_TYPE] = STREAMER_AREA_TYPE_CUBE;
			g_areas[areaID][E_AREA_ID] = CreateDynamicCube(minX, minY, minZ, maxX, maxY, maxZ);
		}
		else if (!strcmp(value, "polygon", true))
		{
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

			new Float:points[MAX_AREA_POLYGON_POINTS * 2];
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
				if (pointIndex >= MAX_AREA_POLYGON_POINTS * 2)
				{
					printf("  Reached limit of %d polygon points", MAX_AREA_POLYGON_POINTS);
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

			g_areas[areaID][E_AREA_TYPE] = STREAMER_AREA_TYPE_POLYGON;
			g_areas[areaID][E_AREA_ID] = CreateDynamicPolygon(points, minZ, maxZ, pointIndex);
		}
		else
		{
			printf("  Invalid area type '%s' for area %d", value, areaID);
			areaNode = XML_GetNextSibling(areaNode, "area");
			continue;
		}

		Streamer_SetIntData(STREAMER_TYPE_AREA, g_areas[areaID][E_AREA_ID], E_STREAMER_EXTRA_ID, areaID);

		areaID++;

		areaNode = XML_GetNextSibling(areaNode, "area");
	}

	printf("  %d areas loaded", areaID);
}