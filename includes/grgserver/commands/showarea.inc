ACMD:showarea(playerID, params[], StringID:69("Show area points as icons on the map"))
{
	new name[STRINGLENGTH_AREANAME];
	if (sscanf(params, "s[" #STRINGLENGTH_AREANAME "]", name))
	{
		CmdUsageMsg(playerID, "showarea", "Name");
		return COMMAND_USAGE;
	}

	Foreach(areaID, g_areas)
	{
		if (StrNotNull(g_areas[areaID][E_AREA_NAME]) && !strcmp(g_areas[areaID][E_AREA_NAME], name, true))
		{
			Count(iconIndex, 100)
			{
				RemovePlayerMapIcon(playerID, iconIndex);
			}

			new Float:points[MAX_AREA_POLYGON_POINTS * 2];
			GetDynamicPolygonPoints(g_areas[areaID][E_AREA_ID], points);
			new numPoints = GetDynamicPolygonNumberPoints(g_areas[areaID][E_AREA_ID]);
			Count(index, numPoints)
			{
				if (index >= 100)
				{
					break;
				}

				new pointIndex = index * 2;
				SetPlayerMapIcon(playerID, index, points[pointIndex], points[pointIndex + 1], 0, 56, MAPICON_GLOBAL);
			}

			SendClientMessageEx(playerID, COLOR_INFO, StringID:70("The area points have been marked on your map"));
			return COMMAND_OK;
		}
	}

	SendClientMessageEx(playerID, COLOR_ERROR, StringID:71("The specified area was not found!"));
	return COMMAND_ERROR;
}