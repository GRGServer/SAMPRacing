IsBanned(playerID, showMessage)
{
	new ip[16];
	GetPlayerIp(playerID, ip, sizeof(ip));
	new userID;
	MySQLQuery("SELECT * FROM `users` WHERE `username` = '%s'", MySQLEscapeString(GetPlayerNameEx(playerID)));
	mysql_store_result();
	userID = strval(GetMySQLField("id"));
	mysql_free_result();
	if (!userID)
	{
		userID = -1;
	}
	MySQLQuery("SELECT * FROM `bans` WHERE `ip` = '%s' OR `userId` = '%d'", ip, userID);
	mysql_store_result();
	new rows = mysql_num_rows();
	if (rows)
	{
		if (showMessage)
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:42("Sorry, but you got banned from this server!"));
			SendClientMessageEx(playerID, COLOR_INFO, StringID:43("Reason for the ban: %s"), GetMySQLField("reason"));
			SendClientMessageEx(playerID, COLOR_INFO, StringID:44("You got banned by mistake? In this case, please contact us on http://www.grgserver.net."));
		}
	}
	mysql_free_result();
	return rows;
}