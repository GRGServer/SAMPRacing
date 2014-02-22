// Fix for warning 208 "function with tag result used before definition, forcing reparse"
forward Cache:mysql_query_format(bool:useCache, query[], {Float,_}:...);