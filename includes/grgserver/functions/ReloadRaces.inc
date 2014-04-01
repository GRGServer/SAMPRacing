ReloadRaces()
{
	print("Loading races...");

	Foreach(index, g_races)
	{
		Foreach(field, g_races[])
		{
			g_races[index][E_RACE:field] = 0;
		}

		Count(npcID, MAX_RACENPCS)
		{
			g_races[index][E_RACE_NPCS][npcID] = -1;
		}

		g_races[index][E_RACE_HOSTPLAYERID] = INVALID_PLAYER_ID;
	}

	DestroyPickupsOfType(PICKUPTYPE_RACE);

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

		new XMLNode:pickupNode = XML_GetFirstChild(raceNode, "pickup");
		if (pickupNode)
		{
			g_races[raceID][E_RACE_PICKUP_POSX] = XML_GetFloatAttribute(pickupNode, "x");
			g_races[raceID][E_RACE_PICKUP_POSY] = XML_GetFloatAttribute(pickupNode, "y");
			g_races[raceID][E_RACE_PICKUP_POSZ] = XML_GetFloatAttribute(pickupNode, "z");

			AddPickup(PICKUPTYPE_RACE, g_races[raceID][E_RACE_PICKUP_POSX], g_races[raceID][E_RACE_PICKUP_POSY], g_races[raceID][E_RACE_PICKUP_POSZ], raceID);
		}

		new spawn;
		new XMLNode:spawnNode = XML_GetFirstChild(raceNode, "spawn");
		while (spawnNode)
		{
			if (spawn >= RACE_PLAYERCOUNT)
			{
				printf("  Reached limit of %d race spawns", RACE_PLAYERCOUNT);
				break;
			}

			g_races[raceID][E_RACE_SPAWN_POSX][spawn] = XML_GetFloatAttribute(spawnNode, "x");
			g_races[raceID][E_RACE_SPAWN_POSY][spawn] = XML_GetFloatAttribute(spawnNode, "y");
			g_races[raceID][E_RACE_SPAWN_POSZ][spawn] = XML_GetFloatAttribute(spawnNode, "z");
			g_races[raceID][E_RACE_SPAWN_ANGLE][spawn] = XML_GetFloatAttribute(spawnNode, "angle");

			spawn++;

			spawnNode = XML_GetNextSibling(spawnNode, "spawn");
		}

		new npcID;
		new XMLNode:npcNode = XML_GetFirstChild(raceNode, "npc");
		while (npcNode)
		{
			if (npcID >= MAX_RACENPCS)
			{
				printf("  Reached limit of %d race NPCs", MAX_RACENPCS);
				break;
			}

			g_races[raceID][E_RACE_NPCS][npcID] = XML_GetIntAttribute(npcNode, "id");

			npcID++;

			npcNode = XML_GetNextSibling(npcNode, "npc");
		}

		raceID++;

		raceNode = XML_GetNextSibling(raceNode, "race");
	}
	XML_UnloadDocument(xml);

	printf("  %d races loaded", raceID);
}