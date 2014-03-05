XML_GetIntAttribute(XMLNode:node, name[])
{
	new value[100];
	XML_GetAttribute(node, name, value);
	return strval(value);
}