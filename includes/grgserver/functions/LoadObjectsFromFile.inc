LoadObjectsFromFile(filename[])
{
	new count;
	new value[100];

	FormatNew:filePath[100]("objects/%s.xml", filename);

	new XMLNode:xml = XML_LoadDocument(filePath);
	xml = XML_GetFirstChild(xml, "objects");
	new XMLNode:objectNode = XML_GetFirstChild(xml, "object");
	while (objectNode)
	{
		XML_GetAttribute(objectNode, "model", value);
		new modelID = strval(value);

		XML_GetAttribute(objectNode, "interior", value);
		new interior = strval(value);

		// Read position
		XML_GetAttribute(objectNode, "posX", value);
		new Float:posX = floatstr(value);
		XML_GetAttribute(objectNode, "posY", value);
		new Float:posY = floatstr(value);
		XML_GetAttribute(objectNode, "posZ", value);
		new Float:posZ = floatstr(value);

		// Read rotation
		XML_GetAttribute(objectNode, "rotX", value);
		new Float:rotX = floatstr(value);
		XML_GetAttribute(objectNode, "rotY", value);
		new Float:rotY = floatstr(value);
		XML_GetAttribute(objectNode, "rotZ", value);
		new Float:rotZ = floatstr(value);

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

		objectNode = XML_GetNextSibling(objectNode, "object");

		count++;
	}
	XML_UnloadDocument(xml);

	return count;
}