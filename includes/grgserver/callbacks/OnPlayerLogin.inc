forward OnPlayerLogin(playerID, password[]);
public OnPlayerLogin(playerID, password[])
{
	new databasePassword[STRINGLENGTH_HASH * 2 + 2];
	cache_get_value(0, "password", databasePassword, STRINGLENGTH_HASH * 2 + 2);

	new salt[STRINGLENGTH_HASH];
	new hash[STRINGLENGTH_HASH];
	sscanf(databasePassword, "p<$>s[" #STRINGLENGTH_HASH "]s[" #STRINGLENGTH_HASH "]", salt, hash);
	if (!IsStr(databasePassword, Hash(password, salt)))
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:25("The entered password is wrong!"));
		ShowDialog:Login(playerID);
		return;
	}

	cache_get_value_int(0, "id", PVar:playerID[USERID]);

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