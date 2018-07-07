ReloadVehicleShops()
{
    print("Loading vehicle shops...");

    Foreach(index, g_vehicleShops)
    {
        Foreach(field, g_vehicleShops[])
        {
            g_vehicleShops[index][E_VEHICLESHOP:field] = 0;
        }
    }

    DestroyPickupsOfType(PICKUPTYPE_VEHICLESHOP);

    new shopID = 0;
    new XMLNode:xml = XML_LoadDocument("vehicleshops.xml");
    xml = XML_GetFirstChild(xml, "vehicleshops");
    new XMLNode:shopNode = XML_GetFirstChild(xml, "shop");
    while (shopNode)
    {
        if (shopID >= MAX_VEHICLESHOPS)
        {
            printf("  Reached limit of %d vehicle shops", MAX_VEHICLESHOPS);
            break;
        }

        new XMLNode:pickupNode = XML_GetFirstChild(shopNode, "pickup");
        if (pickupNode)
        {
            AddPickup(PICKUPTYPE_VEHICLESHOP, XML_GetFloatAttribute(pickupNode, "x"), XML_GetFloatAttribute(pickupNode, "y"), XML_GetFloatAttribute(pickupNode, "z"), shopID);
        }

        new XMLNode:buySpawnNode = XML_GetFirstChild(shopNode, "buyspawn");
        if (buySpawnNode)
        {
            g_vehicleShops[shopID][E_VEHICLESHOP_BUYSPAWN_POSX] = XML_GetFloatAttribute(buySpawnNode, "x");
            g_vehicleShops[shopID][E_VEHICLESHOP_BUYSPAWN_POSY] = XML_GetFloatAttribute(buySpawnNode, "y");
            g_vehicleShops[shopID][E_VEHICLESHOP_BUYSPAWN_POSZ] = XML_GetFloatAttribute(buySpawnNode, "z");
            g_vehicleShops[shopID][E_VEHICLESHOP_BUYSPAWN_ANGLE] = XML_GetFloatAttribute(buySpawnNode, "angle");
        }

        new XMLNode:quitSpawnNode = XML_GetFirstChild(shopNode, "quitspawn");
        if (quitSpawnNode)
        {
            g_vehicleShops[shopID][E_VEHICLESHOP_QUITSPAWN_POSX] = XML_GetFloatAttribute(quitSpawnNode, "x");
            g_vehicleShops[shopID][E_VEHICLESHOP_QUITSPAWN_POSY] = XML_GetFloatAttribute(quitSpawnNode, "y");
            g_vehicleShops[shopID][E_VEHICLESHOP_QUITSPAWN_POSZ] = XML_GetFloatAttribute(quitSpawnNode, "z");
            g_vehicleShops[shopID][E_VEHICLESHOP_QUITSPAWN_ANGLE] = XML_GetFloatAttribute(quitSpawnNode, "angle");
        }

        new XMLNode:numberPlatePrefixNode = XML_GetFirstChild(shopNode, "numberplateprefix");
        if (numberPlatePrefixNode)
        {
            XML_GetValue(XML_GetFirstChild(numberPlatePrefixNode), g_vehicleShops[shopID][E_VEHICLESHOP_NUMBERPLATEPREFIX], STRINGLENGTH_NUMBERPLATE);
        }

        shopID++;

        shopNode = XML_GetNextSibling(shopNode, "shop");
    }
    XML_UnloadDocument(xml);

    printf("  %d vehicle shops loaded", shopID);
}