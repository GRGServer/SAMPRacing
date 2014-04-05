SaveObjects(filename[])
{
	FormatNew:filePath[STRINGLENGTH_OBJECTFILENAME]("objects/%s.xml", filename);

	new XMLNode:xml = XML_CreateDocument(filePath);
	new XMLNode:rootNode = XML_CreateNode(xml, "objects");

	Foreach(arrayIndex, g_objects)
	{
		if (IsStr(filename, g_objects[arrayIndex][E_OBJECT_FILENAME]))
		{
			new objectID = arrayIndex + 1;

			new XMLNode:objectNode = XML_CreateNode(rootNode, "object");

			XML_SetIntAttribute(objectNode, "model", Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectID, E_STREAMER_MODEL_ID));

			new objectInteriors[1];
			Streamer_GetArrayData(STREAMER_TYPE_OBJECT, objectID, E_STREAMER_INTERIOR_ID, objectInteriors, sizeof(objectInteriors));// Interiors are stored in an array (An object can be visible in multiple interiors)
			XML_SetIntAttribute(objectNode, "interior", objectInteriors[0]);// We only use one interior for each object, so element 0 has the correct interior ID

			XML_SetFloatAttribute(objectNode, "posX", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSX]);
			XML_SetFloatAttribute(objectNode, "posY", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSY]);
			XML_SetFloatAttribute(objectNode, "posZ", g_objects[arrayIndex][E_OBJECT_ORIGINAL_POSZ]);

			XML_SetFloatAttribute(objectNode, "rotX", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTX]);
			XML_SetFloatAttribute(objectNode, "rotY", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTY]);
			XML_SetFloatAttribute(objectNode, "rotZ", g_objects[arrayIndex][E_OBJECT_ORIGINAL_ROTZ]);

			if (g_objects[arrayIndex][E_OBJECT_MOVE_POSX] || g_objects[arrayIndex][E_OBJECT_MOVE_POSY] || g_objects[arrayIndex][E_OBJECT_MOVE_POSZ])
			{
				new XMLNode:moveNode = XML_CreateNode(objectNode, "move");

				XML_SetFloatAttribute(moveNode, "posX", g_objects[arrayIndex][E_OBJECT_MOVE_POSX]);
				XML_SetFloatAttribute(moveNode, "posY", g_objects[arrayIndex][E_OBJECT_MOVE_POSY]);
				XML_SetFloatAttribute(moveNode, "posZ", g_objects[arrayIndex][E_OBJECT_MOVE_POSZ]);

				XML_SetFloatAttribute(moveNode, "rotX", g_objects[arrayIndex][E_OBJECT_MOVE_ROTX]);
				XML_SetFloatAttribute(moveNode, "rotY", g_objects[arrayIndex][E_OBJECT_MOVE_ROTY]);
				XML_SetFloatAttribute(moveNode, "rotZ", g_objects[arrayIndex][E_OBJECT_MOVE_ROTZ]);

				XML_SetFloatAttribute(moveNode, "speed", g_objects[arrayIndex][E_OBJECT_MOVE_SPEED]);
			}
		}
	}

	XML_SaveDocument(xml);
	XML_UnloadDocument(xml);
}