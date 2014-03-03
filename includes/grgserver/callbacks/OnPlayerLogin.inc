forward OnPlayerLogin(playerID);
public OnPlayerLogin(playerID)
{
	if (!cache_num_rows())
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:25("The entered password is wrong!"));
		ShowDialog:Login(playerID);
		return;
	}

	PVar:playerID[USERID] = strval(GetMySQLField("id"));

	// Update some stats
	MySQLFormat("UPDATE `users` SET `lastLogin` = NOW() WHERE `id` = %d", PVar:playerID[USERID]);
	mysql_pquery(1, g_sqlQuery);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:27("You have been logged in successfully"));

	// Send login message to all players except the logged in player
	PlayerLoop(currentPlayerID)
	{
		if (currentPlayerID != playerID)
		{
			SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%u logged in"), playerID);
		}
	}

	// Load the player
	LoadPlayer(playerID);
}