SaveObjects(filename[])
{
	new value[100];

	FormatNew:filePath[STRINGLENGTH_OBJECTFILENAME]("objects/%s.xml", filename);

	new XMLNode:xml = XML_CreateDocument(filePath);
	new XMLNode:rootNode = XML_CreateNode(xml, "objects");

	Foreach(arrayIndex, g_objects)
	{
		if (IsStr(filename, g_objects[arrayIndex][E_OBJECT_FILENAME]))
		{
			new objectID = arrayIndex + 1;

			new XMLNode:objectNode = XML_CreateNode(rootNode, "object");

			Format:value("%d", Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectID, E_STREAMER_MODEL_ID));
			XML_SetAttribute(objectNode, "model", value);

			new objectInteriors[1];
			Streamer_GetArrayData(STREAMER_TYPE_OBJECT, objectID, E_STREAMER_INTERIOR_ID, objectInteriors, sizeof(objectInteriors));// Interiors are stored in an array (An object can be visible in multiple interiors)
			Format:value("%d", objectInteriors[0]);// We only use one interior for each object, so element 0 has the correct interior ID
			XML_SetAttribute(objectNode, "interior", value);

			XML_SetFloatAttribute(objectNode, "posX", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSX]);
			XML_SetFloatAttribute(objectNode, "posY", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSY]);
			XML_SetFloatAttribute(objectNode, "posZ", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSZ]);

			XML_SetFloatAttribute(objectNode, "rotX", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTX]);
			XML_SetFloatAttribute(objectNode, "rotY", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTY]);
			XML_SetFloatAttribute(objectNode, "rotZ", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTZ]);
		}
	}

	XML_SaveDocument(xml);
	XML_UnloadDocument(xml);
}