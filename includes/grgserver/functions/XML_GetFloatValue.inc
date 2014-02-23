Float:XML_GetFloatValue(XMLNode:node)
{
	new value[100];
	XML_GetValue(XML_GetFirstChild(node), value);
	return floatstr(value);
}