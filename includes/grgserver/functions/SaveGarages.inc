SaveGarages()
{
    new XMLNode:xml = XML_CreateDocument("garages.xml");
    new XMLNode:rootNode = XML_CreateNode(xml, "garages");

    Foreach(garageNumber, g_garages)
    {
        if (g_garages[garageNumber][E_GARAGE_ID])
        {
            new XMLNode:garageNode = XML_CreateNode(rootNode, "garage");

            XML_SetIntAttribute(garageNode, "id", g_garages[garageNumber][E_GARAGE_ID]);
            XML_SetIntAttribute(garageNode, "price", g_garages[garageNumber][E_GARAGE_PRICE]);
            XML_SetFloatAttribute(garageNode, "enterrange", g_garages[garageNumber][E_GARAGE_ENTERRANGE]);

            new XMLNode:vehicleNode = XML_CreateNode(garageNode, "vehicle");

            XML_SetFloatAttribute(vehicleNode, "x", g_garages[garageNumber][E_GARAGE_VEHICLE_POSX]);
            XML_SetFloatAttribute(vehicleNode, "y", g_garages[garageNumber][E_GARAGE_VEHICLE_POSY]);
            XML_SetFloatAttribute(vehicleNode, "z", g_garages[garageNumber][E_GARAGE_VEHICLE_POSZ]);
            XML_SetFloatAttribute(vehicleNode, "angle", g_garages[garageNumber][E_GARAGE_VEHICLE_ANGLE]);

            new XMLNode:cameraNode = XML_CreateNode(garageNode, "camera");

            XML_SetFloatAttribute(cameraNode, "x", g_garages[garageNumber][E_GARAGE_CAMERA_POSX]);
            XML_SetFloatAttribute(cameraNode, "y", g_garages[garageNumber][E_GARAGE_CAMERA_POSY]);
            XML_SetFloatAttribute(cameraNode, "z", g_garages[garageNumber][E_GARAGE_CAMERA_POSZ]);

            new XMLNode:pickupNode = XML_CreateNode(garageNode, "pickup");

            XML_SetFloatAttribute(pickupNode, "x", g_garages[garageNumber][E_GARAGE_PICKUP_POSX]);
            XML_SetFloatAttribute(pickupNode, "y", g_garages[garageNumber][E_GARAGE_PICKUP_POSY]);
            XML_SetFloatAttribute(pickupNode, "z", g_garages[garageNumber][E_GARAGE_PICKUP_POSZ]);

            if (g_garages[garageNumber][E_GARAGE_DOOROBJECTID])
            {
                new string[10];
                valstr(string, g_garages[garageNumber][E_GARAGE_DOOROBJECTID]);
                XML_CreateNode(XML_CreateNode(garageNode, "doorobject"), string, e_XML_NODE_TEXT);
            }
        }
    }

    XML_SaveDocument(xml);
    XML_UnloadDocument(xml);
}