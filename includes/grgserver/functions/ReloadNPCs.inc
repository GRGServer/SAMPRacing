ReloadNPCs()
{
	print("Loading NPCs...");

	Foreach(index, g_npcs)
	{
		PlayerLoop(playerID)
		{
			if (PVar:playerID[NPCID] == index && IsPlayerNPC(playerID))
			{
				Kick(playerID);
			}
		}

		Foreach(field, g_npcs[])
		{
			g_npcs[index][E_NPC:field] = 0;
		}

		g_npcs[index][E_NPC_ID] = -1;
		g_npcs[index][E_NPC_VEHICLE_ID] = INVALID_VEHICLE_ID;
	}

	new npcID;
	new XMLNode:xml = XML_LoadDocument("npcs.xml");
	xml = XML_GetFirstChild(xml, "npcs");
	new XMLNode:npcNode = XML_GetFirstChild(xml, "npc");
	while (npcNode)
	{
		if (npcID >= MAX_NPCS)
		{
			printf("  Reached limit of %d NPCs", MAX_NPCS);
			break;
		}

		new recordingType[10];
		XML_GetAttribute(npcNode, "type", recordingType);
		if (IsStr(recordingType, "driver"))
		{
			g_npcs[npcID][E_NPC_RECORDING_TYPE] = PLAYER_RECORDING_TYPE_DRIVER;
		}
		else if (IsStr(recordingType, "onfoot"))
		{
			g_npcs[npcID][E_NPC_RECORDING_TYPE] = PLAYER_RECORDING_TYPE_ONFOOT;
		}
		else
		{
			g_npcs[npcID][E_NPC_RECORDING_TYPE] = PLAYER_RECORDING_TYPE_NONE;
		}

		g_npcs[npcID][E_NPC_ID] = XML_GetIntAttribute(npcNode, "id");
		g_npcs[npcID][E_NPC_SKIN] = XML_GetIntAttribute(npcNode, "skin");
		XML_GetAttribute(npcNode, "recording", g_npcs[npcID][E_NPC_RECORDING_NAME], STRINGLENGTH_NPCRECORDINGNAME);

		new XMLNode:vehicleNode = XML_GetFirstChild(npcNode, "vehicle");
		if (vehicleNode)
		{
			g_npcs[npcID][E_NPC_VEHICLE_MODELID] = XML_GetIntAttribute(vehicleNode, "model");
			g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB] = XML_GetIntAttribute(vehicleNode, "paintjob");

			new componentID;

			new XMLNode:componentNode = XML_GetFirstChild(npcNode, "component");
			while (componentNode)
			{
				if (componentID >= MAX_VEHICLECOMPONENT_SLOTS)
				{
					printf("  Reached limit of %d vehicle components", MAX_VEHICLECOMPONENT_SLOTS);
					break;
				}

				new componentString[10];
				XML_GetValue(XML_GetFirstChild(componentNode), componentString);

				g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentID] = strval(componentString);

				componentID++;

				componentNode = XML_GetNextSibling(componentNode, "component");
			}
		}

		SetTimerEx("ConnectNPCEx", (npcID / 10) * 10000, false, "d", npcID);

		npcID++;

		npcNode = XML_GetNextSibling(npcNode, "npc");
	}
	XML_UnloadDocument(xml);

	printf("  %d NPCs loaded", npcID);
}