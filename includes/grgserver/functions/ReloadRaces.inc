ReloadRaces()
{
	print("Loading races...");

	Foreach(index, g_races)
	{
		Foreach(field, g_races[])
		{
			g_races[index][E_RACE:field] = 0;
		}
		g_races[index][E_RACE_HOSTPLAYERID] = INVALID_PLAYER_ID;
	}

	new raceID;
	new XMLNode:xml = XML_LoadDocument("races.xml");
	xml = XML_GetFirstChild(xml, "races");
	new XMLNode:raceNode = XML_GetFirstChild(xml, "race");
	while (raceNode)
	{
		if (raceID >= MAX_RACES)
		{
			printf("  Reached limit of %d races", MAX_RACES);
			break;
		}

		XML_GetAttribute(raceNode, "name", g_races[raceID][E_RACE_NAME], STRINGLENGTH_RACENAME);

		g_races[raceID][E_RACE_LAPS] = XML_GetIntAttribute(raceNode, "laps");
		g_races[raceID][E_RACE_LEVEL] = XML_GetIntAttribute(raceNode, "level");

		new checkpointID;

		new XMLNode:checkpointNode = XML_GetFirstChild(raceNode, "checkpoint");
		while (checkpointNode)
		{
			if (checkpointID >= MAX_RACECHECKPOINTS)
			{
				printf("  Reached limit of %d race checkpoints", MAX_RACECHECKPOINTS);
				break;
			}

			g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointID] = XML_GetFloatAttribute(checkpointNode, "x");
			g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointID] = XML_GetFloatAttribute(checkpointNode, "y");
			g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointID] = XML_GetFloatAttribute(checkpointNode, "z");

			checkpointID++;

			checkpointNode = XML_GetNextSibling(checkpointNode, "checkpoint");
		}

		raceID++;

		raceNode = XML_GetNextSibling(raceNode, "race");
	}
	XML_UnloadDocument(xml);

	printf("  %d races loaded", raceID);
}