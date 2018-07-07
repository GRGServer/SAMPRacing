ReloadInteriors()
{
    print("Loading interiors...");

    Foreach(index, g_interiors)
    {
        Foreach(field, g_interiors[])
        {
            g_interiors[index][E_INTERIOR:field] = 0;
        }
    }

    new interiorID = 0;
    new XMLNode:xml = XML_LoadDocument("interiors.xml");
    xml = XML_GetFirstChild(xml, "interiors");
    new XMLNode:interiorNode = XML_GetFirstChild(xml, "interior");
    while (interiorNode)
    {
        if (interiorID >= MAX_INTERIORS)
        {
            printf("  Reached limit of %d interiors", MAX_INTERIORS);
            break;
        }

        g_interiors[interiorID][E_INTERIOR_ID] = XML_GetIntAttribute(interiorNode, "interior");
        g_interiors[interiorID][E_INTERIOR_POSX] = XML_GetFloatAttribute(interiorNode, "x");
        g_interiors[interiorID][E_INTERIOR_POSY] = XML_GetFloatAttribute(interiorNode, "y");
        g_interiors[interiorID][E_INTERIOR_POSZ] = XML_GetFloatAttribute(interiorNode, "z");
        g_interiors[interiorID][E_INTERIOR_ANGLE] = XML_GetFloatAttribute(interiorNode, "angle");
        XML_GetValue(XML_GetFirstChild(interiorNode), g_interiors[interiorID][E_INTERIOR_NAME], STRINGLENGTH_INTERIORNAME);

        interiorID++;

        interiorNode = XML_GetNextSibling(interiorNode, "interior");
    }
    XML_UnloadDocument(xml);

    printf("  %d interiors loaded", interiorID);
}