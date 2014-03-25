LoadHiddenPackages()
{
	print("Loading hidden packages...");

	new packageID = 0;

	if (fexist("hiddenpackages.xml"))
	{
		new XMLNode:xml = XML_LoadDocument("hiddenpackages.xml");
		xml = XML_GetFirstChild(xml, "hiddenpackages");
		new XMLNode:packageNode = XML_GetFirstChild(xml, "package");
		while (packageNode)
		{
			if (packageID >= MAX_HIDDENPACKAGES)
			{
				printf("  Limit of %d hidden packages reached", MAX_HIDDENPACKAGES);
				break;
			}

			g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX] = XML_GetFloatAttribute(packageNode, "x");
			g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY] = XML_GetFloatAttribute(packageNode, "y");
			g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ] = XML_GetFloatAttribute(packageNode, "z");

			packageID++;

			packageNode = XML_GetNextSibling(packageNode, "package");
		}
		XML_UnloadDocument(xml);
	}
	else
	{
		print("  hiddenpackages.xml not found!");
	}

	g_hiddenPackagesCount = packageID;

	printf("  %d hidden packages loaded", packageID);
}