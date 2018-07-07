XML_SetFloatAttribute(XMLNode:node, name[], Float:value)
{
    FormatNew:string[10]("%f", value);
    XML_SetAttribute(node, name, string);
}