SaveNPCs()
{
    new XMLNode:xml = XML_CreateDocument("npcs.xml");
    new XMLNode:rootNode = XML_CreateNode(xml, "npcs");

    Foreach(npcID, g_npcs)
    {
        if (g_npcs[npcID][E_NPC_ID] == -1)
        {
            continue;
        }

        new XMLNode:npcNode = XML_CreateNode(rootNode, "npc");

        new recordingType[10];
        switch (g_npcs[npcID][E_NPC_RECORDING_TYPE])
        {
            case PLAYER_RECORDING_TYPE_DRIVER:
            {
                recordingType = "driver";
            }
            case PLAYER_RECORDING_TYPE_NONE:
            {
                recordingType = "none";
            }
            default:
            {
                recordingType = "onfoot";
            }
        }

        XML_SetIntAttribute(npcNode, "id", g_npcs[npcID][E_NPC_ID]);
        XML_SetIntAttribute(npcNode, "skin", g_npcs[npcID][E_NPC_SKIN]);
        XML_SetIntAttribute(npcNode, "interior", g_npcs[npcID][E_NPC_INTERIOR]);
        XML_SetAttribute(npcNode, "type", recordingType);
        XML_SetAttribute(npcNode, "recording", g_npcs[npcID][E_NPC_RECORDING_NAME]);

        if (g_npcs[npcID][E_NPC_VEHICLE_MODELID])
        {
            new XMLNode:vehicleNode = XML_CreateNode(npcNode, "vehicle");

            XML_SetIntAttribute(vehicleNode, "model", g_npcs[npcID][E_NPC_VEHICLE_MODELID]);
            XML_SetIntAttribute(vehicleNode, "paintjob", g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB]);

            Count(componentSlot, MAX_VEHICLECOMPONENT_SLOTS)
            {
                if (g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot])
                {
                    new componentString[10];
                    valstr(componentString, g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot]);
                    XML_CreateNode(XML_CreateNode(vehicleNode, "component"), componentString, e_XML_NODE_TEXT);
                }
            }
        }
    }

    XML_SaveDocument(xml);
    XML_UnloadDocument(xml);
}