Float:XML_GetFloatAttribute(XMLNode:node, name[])
{
    new value[100];
    XML_GetAttribute(node, name, value);
    return floatstr(value);
}