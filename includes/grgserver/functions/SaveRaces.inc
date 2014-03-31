SaveRaces()
{
	new XMLNode:xml = XML_CreateDocument("races.xml");
	new XMLNode:rootNode = XML_CreateNode(xml, "races");

	Foreach(raceID, g_races)
	{
		if (!g_races[raceID][E_RACE_CHECKPOINT_POSX][0] && !g_races[raceID][E_RACE_CHECKPOINT_POSY][0] && !g_races[raceID][E_RACE_CHECKPOINT_POSZ][0])
		{
			continue;
		}

		new XMLNode:raceNode = XML_CreateNode(rootNode, "race");

		if (!StrNotNull(g_races[raceID][E_RACE_NAME]))
		{
			strcat(g_races[raceID][E_RACE_NAME], "Untitled Race", STRINGLENGTH_RACENAME);
		}

		XML_SetAttribute(raceNode, "name", g_races[raceID][E_RACE_NAME]);

		if (g_races[raceID][E_RACE_LAPS] < 1)
		{
			g_races[raceID][E_RACE_LAPS] = 1;
		}

		XML_SetIntAttribute(raceNode, "laps", g_races[raceID][E_RACE_LAPS]);

		if (g_races[raceID][E_RACE_LEVEL] < 1)
		{
			g_races[raceID][E_RACE_LEVEL] = 1;
		}

		XML_SetIntAttribute(raceNode, "level", g_races[raceID][E_RACE_LEVEL]);

		new XMLNode:pickupNode = XML_CreateNode(raceNode, "pickup");

		XML_SetFloatAttribute(pickupNode, "x", g_races[raceID][E_RACE_PICKUP_POSX]);
		XML_SetFloatAttribute(pickupNode, "y", g_races[raceID][E_RACE_PICKUP_POSY]);
		XML_SetFloatAttribute(pickupNode, "z", g_races[raceID][E_RACE_PICKUP_POSZ]);

		Count(checkpointID, MAX_RACECHECKPOINTS)
		{
			if (!g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointID] && !g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointID])
			{
				continue;
			}

			new XMLNode:checkpointNode = XML_CreateNode(raceNode, "checkpoint");

			XML_SetFloatAttribute(checkpointNode, "x", g_races[raceID][E_RACE_CHECKPOINT_POSX][checkpointID]);
			XML_SetFloatAttribute(checkpointNode, "y", g_races[raceID][E_RACE_CHECKPOINT_POSY][checkpointID]);
			XML_SetFloatAttribute(checkpointNode, "z", g_races[raceID][E_RACE_CHECKPOINT_POSZ][checkpointID]);
		}

		Count(npcID, MAX_RACENPCS)
		{
			if (g_races[raceID][E_RACE_NPCS][npcID] != -1)
			{
				new XMLNode:npcNode = XML_CreateNode(raceNode, "npc");

				XML_SetIntAttribute(npcNode, "id", g_races[raceID][E_RACE_NPCS][npcID]);
			}
		}
	}

	XML_SaveDocument(xml);
	XML_UnloadDocument(xml);
}