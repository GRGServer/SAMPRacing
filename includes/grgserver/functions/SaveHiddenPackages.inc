SaveHiddenPackages()
{
	new XMLNode:document = XML_CreateDocument("hiddenpackages.xml");
	new XMLNode:rootNode = XML_CreateNode(document, "hiddenpackages");

	Foreach(pickupID, g_pickups)
	{
		if (g_pickups[pickupID][E_PICKUP_TYPE] == PICKUPTYPE_HIDDENPACKAGE)
		{
			new XMLNode:packageNode = XML_CreateNode(rootNode, "package");
			XML_SetFloatAttribute(packageNode, "x", g_pickups[pickupID][E_PICKUP_POSX]);
			XML_SetFloatAttribute(packageNode, "y", g_pickups[pickupID][E_PICKUP_POSY]);
			XML_SetFloatAttribute(packageNode, "z", g_pickups[pickupID][E_PICKUP_POSZ]);
		}
	}

	XML_SaveDocument(document);
}