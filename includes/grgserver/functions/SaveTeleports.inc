SaveTeleports()
{
    new XMLNode:xml = XML_CreateDocument("teleports.xml");
    new XMLNode:rootNode = XML_CreateNode(xml, "teleports");

    Foreach(teleportID, g_teleports)
    {
        if (!StrNotNull(g_teleports[teleportID][E_TELEPORT_NAME]))
        {
            continue;
        }

        new string[10];
        new XMLNode:teleportNode = XML_CreateNode(rootNode, "teleport");

        XML_CreateNode(XML_CreateNode(teleportNode, "name"), g_teleports[teleportID][E_TELEPORT_NAME], e_XML_NODE_TEXT);

        if (g_teleports[teleportID][E_TELEPORT_WITHVEHICLE])
        {
            XML_CreateNode(XML_CreateNode(teleportNode, "withvehicle"), "true", e_XML_NODE_TEXT);
        }

        if (g_teleports[teleportID][E_TELEPORT_ADMINSONLY])
        {
            XML_CreateNode(XML_CreateNode(teleportNode, "adminsonly"), "true", e_XML_NODE_TEXT);
        }

        new XMLNode:positionNode = XML_CreateNode(teleportNode, "position");

        Format:string("%f", g_teleports[teleportID][E_TELEPORT_POSX]);
        XML_CreateNode(XML_CreateNode(positionNode, "x"), string, e_XML_NODE_TEXT);

        Format:string("%f", g_teleports[teleportID][E_TELEPORT_POSY]);
        XML_CreateNode(XML_CreateNode(positionNode, "y"), string, e_XML_NODE_TEXT);

        Format:string("%f", g_teleports[teleportID][E_TELEPORT_POSZ]);
        XML_CreateNode(XML_CreateNode(positionNode, "z"), string, e_XML_NODE_TEXT);

        Format:string("%f", g_teleports[teleportID][E_TELEPORT_ANGLE]);
        XML_CreateNode(XML_CreateNode(positionNode, "angle"), string, e_XML_NODE_TEXT);

        Format:string("%d", g_teleports[teleportID][E_TELEPORT_INTERIOR]);
        XML_CreateNode(XML_CreateNode(positionNode, "interior"), string, e_XML_NODE_TEXT);
    }

    XML_SaveDocument(xml);
    XML_UnloadDocument(xml);
}