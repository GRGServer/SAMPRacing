ReloadVehicleModels()
{
    print("Loading vehicle models...");

    Foreach(index, g_vehicleModels)
    {
        Foreach(field, g_vehicleModels[])
        {
            g_vehicleModels[index][E_VEHICLEMODEL:field] = 0;
        }

        Count(field, MAX_TUNINGPARTSPERVEHICLE)
        {
            g_vehicleModels[index][E_VEHICLEMODEL_TUNINGPARTS][field] = -1;
        }
    }

    Foreach(index, g_tuningParts)
    {
        Foreach(field, g_tuningParts[])
        {
            g_tuningParts[index][E_TUNINGPART:field] = 0;
        }
    }

    new count;
    new tuningPartIndex;
    new XMLNode:xml = XML_LoadDocument("vehiclemodels.xml");
    xml = XML_GetFirstChild(xml, "vehiclemodels");
    new XMLNode:modelNode = XML_GetFirstChild(xml, "model");
    while (modelNode)
    {
        new modelID = XML_GetIntAttribute(modelNode, "id");
        if (modelID < 400 || modelID > 611)
        {
            printf("Invalid vehicle model ID: %d", modelID);
            modelNode = XML_GetNextSibling(modelNode, "model");
            continue;
        }

        new arrayIndex = modelID - 400;// First array element starts with 0, vehicle models are starting with 400 (400 - 400 = 0, 401 - 400 = 1, ...)

        XML_GetAttribute(modelNode, "name", g_vehicleModels[arrayIndex][E_VEHICLEMODEL_NAME], STRINGLENGTH_VEHICLENAME);
        XML_GetAttribute(modelNode, "type", g_vehicleModels[arrayIndex][E_VEHICLEMODEL_TYPE], STRINGLENGTH_VEHICLETYPE);

        g_vehicleModels[arrayIndex][E_VEHICLEMODEL_PRICE] = XML_GetIntAttribute(modelNode, "price");

        new tuningPartSlot;
        new XMLNode:tuningPartNode = XML_GetFirstChild(modelNode, "tuningpart");
        while (tuningPartNode)
        {
            if (tuningPartSlot >= MAX_TUNINGPARTSPERVEHICLE)
            {
                printf("Reached limit of %d tuning parts for vehicle %d", MAX_TUNINGPARTSPERVEHICLE, modelID);
                break;
            }

            new type[16];
            XML_GetAttribute(tuningPartNode, "type", type);

            g_tuningParts[tuningPartIndex][E_TUNINGPART_MODELID] = XML_GetIntAttribute(tuningPartNode, "model");
            g_tuningParts[tuningPartIndex][E_TUNINGPART_PRICE] = XML_GetIntAttribute(tuningPartNode, "price");
            g_tuningParts[tuningPartIndex][E_TUNINGPART_TYPE] = GetTuningPartByName(type);

            new XMLNode:offsetNode = XML_GetFirstChild(tuningPartNode, "offset");
            if (offsetNode)
            {
                g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSETX] = XML_GetFloatAttribute(offsetNode, "x");
                g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSETY] = XML_GetFloatAttribute(offsetNode, "y");
                g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSETZ] = XML_GetFloatAttribute(offsetNode, "z");
            }

            new XMLNode:rotationNode = XML_GetFirstChild(tuningPartNode, "rotation");
            if (rotationNode)
            {
                g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTX] = XML_GetFloatAttribute(rotationNode, "x");
                g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTY] = XML_GetFloatAttribute(rotationNode, "y");
                g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTZ] = XML_GetFloatAttribute(rotationNode, "z");
            }

            g_vehicleModels[arrayIndex][E_VEHICLEMODEL_TUNINGPARTS][tuningPartSlot] = tuningPartIndex;

            tuningPartSlot++;
            tuningPartIndex++;

            tuningPartNode = XML_GetNextSibling(tuningPartNode, "tuningpart");
        }

        count++;

        modelNode = XML_GetNextSibling(modelNode, "model");
    }
    XML_UnloadDocument(xml);

    printf("  %d vehicle models loaded", count);
}