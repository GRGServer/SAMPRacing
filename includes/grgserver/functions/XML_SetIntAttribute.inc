XML_SetIntAttribute(XMLNode:node, name[], value)
{
    new string[10];
    valstr(string, value);
    XML_SetAttribute(node, name, string);
}