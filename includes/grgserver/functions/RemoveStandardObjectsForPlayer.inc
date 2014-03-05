RemoveStandardObjectsForPlayer(playerID)
{
	new XMLNode:xml = XML_LoadDocument("removedstandardobjects.xml");
	xml = XML_GetFirstChild(xml, "objects");
	new XMLNode:objectNode = XML_GetFirstChild(xml, "object");
	while (objectNode)
	{
		RemoveBuildingForPlayer(playerID, XML_GetIntAttribute(objectNode, "model"), XML_GetFloatAttribute(objectNode, "x"), XML_GetFloatAttribute(objectNode, "y"), XML_GetFloatAttribute(objectNode, "z"), XML_GetFloatAttribute(objectNode, "radius"));

		objectNode = XML_GetNextSibling(objectNode, "object");
	}
}