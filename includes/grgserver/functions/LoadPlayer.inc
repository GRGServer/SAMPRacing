LoadPlayer(playerID)
{
	MySQLQuery("SELECT `language`, `isAdmin` FROM `users` WHERE `id` = '%d'", PVar:playerID[USERID]);
	mysql_store_result();
	PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	PVar:playerID[ISADMIN] = strval(GetMySQLField("isAdmin"));
	mysql_free_result();
}