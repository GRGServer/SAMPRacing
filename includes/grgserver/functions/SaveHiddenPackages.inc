SaveHiddenPackages()
{
    new XMLNode:xml = XML_CreateDocument("hiddenpackages.xml");
    new XMLNode:rootNode = XML_CreateNode(xml, "hiddenpackages");

    Foreach(packageID, g_hiddenPackages)
    {
        new Float:posX = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSX];
        new Float:posY = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSY];
        new Float:posZ = g_hiddenPackages[packageID][E_HIDDENPACKAGE_POSZ];

        if (posX || posY || posZ)
        {
            new XMLNode:packageNode = XML_CreateNode(rootNode, "package");

            XML_SetFloatAttribute(packageNode, "x", posX);
            XML_SetFloatAttribute(packageNode, "y", posY);
            XML_SetFloatAttribute(packageNode, "z", posZ);
        }
    }

    XML_SaveDocument(xml);
	XML_UnloadDocument(xml);
}