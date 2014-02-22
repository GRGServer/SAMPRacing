LoadPlayer(playerID)
{
	new Cache:result = mysql_query_format(true, "SELECT `language`, `isAdmin` FROM `users` WHERE `id` = '%d'", PVar:playerID[USERID]);
	PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	PVar:playerID[ISADMIN] = strval(GetMySQLField("isAdmin"));
	cache_delete(result);
}