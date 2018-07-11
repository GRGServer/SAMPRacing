SaveTuningGarages()
{
    new XMLNode:xml = XML_CreateDocument("tuninggarages.xml");
    new XMLNode:rootNode = XML_CreateNode(xml, "tuninggarages");

    Foreach(tuningGarageNumber, g_tuningGarages)
    {
        if (g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ID])
        {
            new XMLNode:tuningGarageNode = XML_CreateNode(rootNode, "tuninggarage");

            XML_SetIntAttribute(tuningGarageNode, "id", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ID]);

            new XMLNode:vehicleNode = XML_CreateNode(tuningGarageNode, "vehicle");

            XML_SetFloatAttribute(vehicleNode, "x", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX]);
            XML_SetFloatAttribute(vehicleNode, "y", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY]);
            XML_SetFloatAttribute(vehicleNode, "z", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ]);
            XML_SetFloatAttribute(vehicleNode, "angle", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_ANGLE]);

            new XMLNode:cameraNode = XML_CreateNode(tuningGarageNode, "camera");

            XML_SetFloatAttribute(cameraNode, "x", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSX]);
            XML_SetFloatAttribute(cameraNode, "y", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSY]);
            XML_SetFloatAttribute(cameraNode, "z", g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSZ]);
        }
    }

    XML_SaveDocument(xml);
    XML_UnloadDocument(xml);
}