// Fixed for warning 208 "function with tag result used before definition, forcing reparse"
forward Cache:mysql_query_format(bool:useCache, query[], {Float,_}:...);
forward Float:XML_GetFloatValue(XMLNode:node);