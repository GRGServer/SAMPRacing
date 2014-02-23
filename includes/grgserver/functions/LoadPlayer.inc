LoadPlayer(playerID)
{
	new Cache:result = mysql_query_format(true, "SELECT `language`, `isAdmin`, `money` FROM `users` WHERE `id` = '%d'", PVar:playerID[USERID]);
	PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	PVar:playerID[ISADMIN] = strval(GetMySQLField("isAdmin"));

	ResetPlayerMoney(playerID);
	GivePlayerMoney(playerID, strval(GetMySQLField("money")));

	cache_delete(result);
}