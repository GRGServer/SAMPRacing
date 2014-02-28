ReloadHiddenPackages()
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
			if (!AddPickup(PICKUPTYPE_HIDDENPACKAGE, XML_GetFloatAttribute(packageNode, "x"), XML_GetFloatAttribute(packageNode, "y"), XML_GetFloatAttribute(packageNode, "z"), packageID))
			{
				break;
			}

			packageID++;

			packageNode = XML_GetNextSibling(packageNode, "package");
		}
	}
	else
	{
		print("  hiddenpackages.xml not found!");
	}

	g_hiddenPackagesCount = packageID;

	printf("  %d hidden packages loaded", packageID);
}