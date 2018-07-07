LoadPlayer(playerID)
{
	MySQLFormat("SELECT `posX`, `posY`, `posZ`, `angle`, `interior`, `skin`, `language`, `isAdmin`, `level`, `money` FROM `users` WHERE `id` = %d", PVar:playerID[USERID]);
	mysql_pquery(g_mysql, g_sqlQuery, "OnPlayerDataLoaded", "d", playerID);

	MySQLFormat("SELECT `packageId` FROM `hiddenpackages` WHERE `userId` = %d", PVar:playerID[USERID]);
	mysql_pquery(g_mysql, g_sqlQuery, "OnPlayerHiddenPackagesLoaded", "d", playerID);

	MySQLFormat("SELECT `id` FROM `garages` WHERE `userId` = %d", PVar:playerID[USERID]);
	mysql_pquery(g_mysql, g_sqlQuery, "OnPlayerGaragesLoaded", "d", playerID);
}