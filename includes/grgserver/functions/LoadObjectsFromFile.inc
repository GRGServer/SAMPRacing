LoadObjectsFromFile(filename[])
{
	new count;

	FormatNew:filePath[100]("objects/%s.xml", filename);

	new XMLNode:xml = XML_LoadDocument(filePath);
	xml = XML_GetFirstChild(xml, "objects");
	new XMLNode:objectNode = XML_GetFirstChild(xml, "object");
	while (objectNode)
	{
		new modelID = XML_GetIntAttribute(objectNode, "model");
		new interior = XML_GetIntAttribute(objectNode, "interior");

		// Read position
		new Float:posX = XML_GetFloatAttribute(objectNode, "posX");
		new Float:posY = XML_GetFloatAttribute(objectNode, "posY");
		new Float:posZ = XML_GetFloatAttribute(objectNode, "posZ");

		// Read rotation
		new Float:rotX = XML_GetFloatAttribute(objectNode, "rotX");
		new Float:rotY = XML_GetFloatAttribute(objectNode, "rotY");
		new Float:rotZ = XML_GetFloatAttribute(objectNode, "rotZ");

		new objectID = CreateDynamicObject(modelID, posX, posY, posZ, rotX, rotY, rotZ, -1, interior);
		if (objectID > MAX_DYNAMIC_OBJECTS)
		{
			printf("  Limit of %d objects reached", MAX_DYNAMIC_OBJECTS);
			break;
		}

		strcat(Object:objectID[FILENAME], filename, STRINGLENGTH_OBJECTFILENAME);

		Object:objectID[ORIGINAL_POSX] = posX;
		Object:objectID[ORIGINAL_POSY] = posY;
		Object:objectID[ORIGINAL_POSZ] = posZ;
		Object:objectID[ORIGINAL_ROTX] = rotX;
		Object:objectID[ORIGINAL_ROTY] = rotY;
		Object:objectID[ORIGINAL_ROTZ] = rotZ;

		new XMLNode:moveNode = XML_GetFirstChild(objectNode, "move");
		if (moveNode)
		{
			// Read position
			Object:objectID[MOVE_POSX] = XML_GetFloatAttribute(moveNode, "posX");
			Object:objectID[MOVE_POSY] = XML_GetFloatAttribute(moveNode, "posY");
			Object:objectID[MOVE_POSZ] = XML_GetFloatAttribute(moveNode, "posZ");

			// Read rotation
			Object:objectID[MOVE_ROTX] = XML_GetFloatAttribute(moveNode, "rotX");
			Object:objectID[MOVE_ROTY] = XML_GetFloatAttribute(moveNode, "rotY");
			Object:objectID[MOVE_ROTZ] = XML_GetFloatAttribute(moveNode, "rotZ");

			// Read speed
			Object:objectID[MOVE_SPEED] = XML_GetFloatAttribute(moveNode, "speed");

			// Read reset timeout
			Object:objectID[MOVE_RESET_TIMEOUT] = XML_GetIntAttribute(moveNode, "reset");
		}

		objectNode = XML_GetNextSibling(objectNode, "object");

		count++;
	}
	XML_UnloadDocument(xml);

	return count;
}