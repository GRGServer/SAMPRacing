LoadPlayer(playerID)
{
	MySQLFormat("SELECT `posX`, `posY`, `posZ`, `angle`, `interior`, `language`, `isAdmin`, `money` FROM `users` WHERE `id` = %d", PVar:playerID[USERID]);
	mysql_pquery(1, g_sqlQuery, "OnPlayerDataLoaded", "d", playerID);

	MySQLFormat("SELECT `packageId` FROM `hiddenpackages` WHERE `userId` = %d", PVar:playerID[USERID]);
	mysql_pquery(1, g_sqlQuery, "OnPlayerHiddenPackagesLoaded", "d", playerID);
}