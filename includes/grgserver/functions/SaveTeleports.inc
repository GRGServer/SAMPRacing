SaveTeleports()
{
	new XMLNode:document = XML_CreateDocument("teleports.xml");
	new XMLNode:rootNode = XML_CreateNode(document, "teleports");

	Foreach(teleportID, teleports)
	{
		if (!StrNotNull(teleports[teleportID][TELEPORT_NAME]))
		{
			continue;
		}

		new string[10];
		new XMLNode:teleportNode = XML_CreateNode(rootNode, "teleport");

		XML_CreateNode(XML_CreateNode(teleportNode, "name"), teleports[teleportID][TELEPORT_NAME], e_XML_NODE_TEXT);

		if (StrNotNull(teleports[teleportID][TELEPORT_COMMAND]))
		{
			XML_CreateNode(XML_CreateNode(teleportNode, "command"), teleports[teleportID][TELEPORT_COMMAND], e_XML_NODE_TEXT);
		}

		if (teleports[teleportID][TELEPORT_WITHVEHICLE])
		{
			XML_CreateNode(XML_CreateNode(teleportNode, "withvehicle"), "true", e_XML_NODE_TEXT);
		}

		if (teleports[teleportID][TELEPORT_ADMINSONLY])
		{
			XML_CreateNode(XML_CreateNode(teleportNode, "adminsonly"), "true", e_XML_NODE_TEXT);
		}

		new XMLNode:positionNode = XML_CreateNode(teleportNode, "position");

		Format:string("%f", teleports[teleportID][TELEPORT_POSX]);
		XML_CreateNode(XML_CreateNode(positionNode, "x"), string, e_XML_NODE_TEXT);

		Format:string("%f", teleports[teleportID][TELEPORT_POSY]);
		XML_CreateNode(XML_CreateNode(positionNode, "y"), string, e_XML_NODE_TEXT);

		Format:string("%f", teleports[teleportID][TELEPORT_POSZ]);
		XML_CreateNode(XML_CreateNode(positionNode, "z"), string, e_XML_NODE_TEXT);

		Format:string("%f", teleports[teleportID][TELEPORT_ANGLE]);
		XML_CreateNode(XML_CreateNode(positionNode, "angle"), string, e_XML_NODE_TEXT);

		Format:string("%d", teleports[teleportID][TELEPORT_INTERIOR]);
		XML_CreateNode(XML_CreateNode(positionNode, "interior"), string, e_XML_NODE_TEXT);
	}

	XML_SaveDocument(document);
}