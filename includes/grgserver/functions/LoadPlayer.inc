LoadPlayer(playerID)
{
	MySQLQuery("SELECT * FROM `users` WHERE `id` = '%d'", PVar:playerID[USERID]);
	mysql_store_result();

	PVar:playerID[ONLINESINCE] = gettime();
	PVar:playerID[REGISTERED] = strval(GetMySQLField("register"));
	PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	PVar:playerID[ISADMIN] = strval(GetMySQLField("admin"));
	
	
	SetPlayerMoney(playerID, MONEY_CASH, floatstr(GetMySQLField("money")));
	SetPlayerSkin(playerID, PVar:playerID[SKIN]);
	new Float:health = floatstr(GetMySQLField("health"));
	if (!health)
	{
		health = 100;
	}
	SetPlayerHealth(playerID, health);

	mysql_free_result();

	MySQLQuery("SELECT * FROM `permissions` WHERE `userId` = '%d'", PVar:playerID[USERID]);
	mysql_store_result();

	if (mysql_num_rows())
	{
		LoadPlayerPermissions(playerID);
	}

	mysql_free_result();
}