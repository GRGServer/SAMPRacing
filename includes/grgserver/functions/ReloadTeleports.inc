ReloadTeleports()
{
    print("Loading teleports...");

    Foreach(index, g_teleports)
    {
        Foreach(field, g_teleports[])
        {
            g_teleports[index][E_TELEPORT:field] = 0;
        }
    }

    new teleportID = 0;
    new XMLNode:xml = XML_LoadDocument("teleports.xml");
    xml = XML_GetFirstChild(xml, "teleports");
    new XMLNode:teleportNode = XML_GetFirstChild(xml, "teleport");
    while (teleportNode)
    {
        new XMLNode:node;
        new string[10];

        if (teleportID >= MAX_TELEPORTS)
        {
            printf("  Reached limit of %d teleports", MAX_TELEPORTS);
            break;
        }

        // Read "name" value
        node = XML_GetFirstChild(teleportNode, "name");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), g_teleports[teleportID][E_TELEPORT_NAME], STRINGLENGTH_TELEPORTNAME);
        }
        else
        {
            printf("  Node 'name' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        // Read "withvehicle" value
        g_teleports[teleportID][E_TELEPORT_WITHVEHICLE] = false;
        node = XML_GetFirstChild(teleportNode, "withvehicle");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            if (StrNotNull(string) && !strcmp(string, "true", true))
            {
                g_teleports[teleportID][E_TELEPORT_WITHVEHICLE] = true;
            }
        }

        // Read "adminsonly" value
        g_teleports[teleportID][E_TELEPORT_ADMINSONLY] = false;
        node = XML_GetFirstChild(teleportNode, "adminsonly");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            if (StrNotNull(string) && !strcmp(string, "true", true))
            {
                g_teleports[teleportID][E_TELEPORT_ADMINSONLY] = true;
            }
        }

        // Read "position" node
        new XMLNode:positionNode = XML_GetFirstChild(teleportNode, "position");
        if (!positionNode)
        {
            printf("  Node 'position' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        node = XML_GetFirstChild(positionNode, "x");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            g_teleports[teleportID][E_TELEPORT_POSX] = floatstr(string);
        }
        else
        {
            printf("  Node 'x' in node 'position' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        node = XML_GetFirstChild(positionNode, "y");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            g_teleports[teleportID][E_TELEPORT_POSY] = floatstr(string);
        }
        else
        {
            printf("  Node 'y' in node 'position' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        node = XML_GetFirstChild(positionNode, "z");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            g_teleports[teleportID][E_TELEPORT_POSZ] = floatstr(string);
        }
        else
        {
            printf("  Node 'z' in node 'position' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        node = XML_GetFirstChild(positionNode, "angle");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            g_teleports[teleportID][E_TELEPORT_ANGLE] = floatstr(string);
        }
        else
        {
            printf("  Node 'angle' in node 'position' missing for teleport %d", teleportID);
            teleportNode = XML_GetNextSibling(teleportNode, "teleport");
            continue;
        }

        node = XML_GetFirstChild(positionNode, "interior");
        if (node)
        {
            XML_GetValue(XML_GetFirstChild(node), string);
            g_teleports[teleportID][E_TELEPORT_INTERIOR] = strval(string);
        }
        else
        {
            g_teleports[teleportID][E_TELEPORT_INTERIOR] = 0;
        }

        teleportID++;

        teleportNode = XML_GetNextSibling(teleportNode, "teleport");
    }
    XML_UnloadDocument(xml);

    printf("  %d teleports loaded", teleportID);
}