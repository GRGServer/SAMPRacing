LoadNPCs()
{
	print("* Loading NPCs...");
	new arrayIndex;
	new XMLNode:xml = XML_LoadDocument(FILE_NPCS);
	xml = XML_GetFirstChild(xml, "npcs");
	new XMLNode:npcNode = XML_GetFirstChild(xml, "npc");
	while (npcNode)
	{
		if (arrayIndex >= MAX_NPCS)
		{
			printf("  MAX_NPCS (%d) reached!", MAX_NPCS);
			break;
		}

		new value[100];

		// Basic NPC data
		XML_GetAttribute(npcNode, "name", npcs[arrayIndex][NPC_NAME], MAX_PLAYER_NAME);
		XML_GetAttribute(npcNode, "skin", value);
		npcs[arrayIndex][NPC_SKIN] = strval(value);

		// Recording if specified
		new XMLNode:recordingNode = XML_GetFirstChild(npcNode, "recording");
		if (recordingNode)
		{
			XML_GetAttribute(recordingNode, "name", npcs[arrayIndex][NPC_RECORDING], STRINGLENGTH_NPCRECORDINGNAME);
			XML_GetAttribute(recordingNode, "startDelay", value);
			npcs[arrayIndex][NPC_STARTDELAY] = strval(value);
			XML_GetAttribute(recordingNode, "autoStart", value);
			npcs[arrayIndex][NPC_AUTOSTART] = strval(value);
			XML_GetAttribute(recordingNode, "autoRepeat", value);
			npcs[arrayIndex][NPC_AUTOREPEAT] = strval(value);
		}

		// Vehicle if specified
		new XMLNode:vehicleNode = XML_GetFirstChild(npcNode, "vehicle");
		if (vehicleNode)
		{
			XML_GetAttribute(vehicleNode, "model", value);
			new modelID = strval(value);
			XML_GetAttribute(vehicleNode, "color1", value);
			new color1 = strval(value);
			XML_GetAttribute(vehicleNode, "color2", value);
			new color2 = strval(value);
			if (color1 == -1 || color2 == -1)
			{
				GetVehicleColor(modelID, color1, color2);
			}
			npcs[arrayIndex][NPC_VEHICLECOLORS][0] = color1;
			npcs[arrayIndex][NPC_VEHICLECOLORS][1] = color2;
			new vehicleID = AddStaticVehicle(modelID, 0, 0, -100, 0, color1, color2);
			VehicleProperty:vehicleID[NPC_ONLY] = true;
			npcs[arrayIndex][NPC_VEHICLEID] = vehicleID;
		}

		// Spawn position if specified
		new XMLNode:spawnNode = XML_GetFirstChild(npcNode, "spawn");
		if (spawnNode)
		{
			XML_GetAttribute(spawnNode, "posX", value);
			npcs[arrayIndex][NPC_SPAWNPOS][0] = floatstr(value);
			XML_GetAttribute(spawnNode, "posY", value);
			npcs[arrayIndex][NPC_SPAWNPOS][1] = floatstr(value);
			XML_GetAttribute(spawnNode, "posZ", value);
			npcs[arrayIndex][NPC_SPAWNPOS][2] = floatstr(value);
			XML_GetAttribute(spawnNode, "angle", value);
			npcs[arrayIndex][NPC_SPAWNANGLE] = floatstr(value);
		}

		SetTimerEx("Timer_ConnectNPC", arrayIndex * NPC_CONNECT_DELAY, false, "d", arrayIndex);

		npcNode = XML_GetNextSibling(npcNode, "npc");
		arrayIndex++;
	}
	XML_UnloadDocument(xml);
	printf("  %d NPCs loaded", arrayIndex);
}