ReloadPickups()
{
    print("Loading pickups...");

    // Destroy all pickups of types which are loaded by this function
    DestroyPickupsOfType(PICKUPTYPE_HOSPITAL);

    new index = 0;
    new XMLNode:xml = XML_LoadDocument("pickups.xml");
    xml = XML_GetFirstChild(xml, "pickups");
    new XMLNode:pickupNode = XML_GetFirstChild(xml, "pickup");
    while (pickupNode)
    {
        new value[100];
        XML_GetAttribute(pickupNode, "type", value);
        if (IsStr(value, "hospital"))
        {
            AddPickup(PICKUPTYPE_HOSPITAL, XML_GetFloatAttribute(pickupNode, "x"), XML_GetFloatAttribute(pickupNode, "y"), XML_GetFloatAttribute(pickupNode, "z"), 0);
        }
        else
        {
            printf("  Invalid pickup type '%s' for pickup %d", value, index);
            pickupNode = XML_GetNextSibling(pickupNode, "pickup");
            continue;
        }

        index++;

        pickupNode = XML_GetNextSibling(pickupNode, "pickup");
    }
    XML_UnloadDocument(xml);

    printf("  %d pickups loaded", index);
}