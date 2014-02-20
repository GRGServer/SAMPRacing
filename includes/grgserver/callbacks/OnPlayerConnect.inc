public OnPlayerConnect(playerid)
{
	// Reset all player variables to their default values
	ResetPlayerVariables(playerid);

	printf("%s connected from %s", GetPlayerNameEx(playerid), GetPlayerCountryName(playerid));

	// Send join message to all players except the joined player
	PlayerLoop(playerID)
	{
		if (!IsPlayerNPC(playerID) && playerID != playerid)
		{
			SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:23("%u has joined the server"), playerid);
		}
	}

	// Check whether the player is already registered
	MySQLQuery("SELECT `id` FROM `users` WHERE `username` = '%s'", MySQLEscapeString(GetPlayerNameEx(playerid)));
	mysql_store_result();
	new rows = mysql_num_rows();
	mysql_free_result();

	if (rows)
	{
		// Show login dialog
		ShowDialog:Login(playerid);
	}
	else
	{
		// Show language selection of register process
		ShowDialog:Register_Language(playerid);
	}

	CreatePlayerTextDraws(playerid);

	TextDrawShowForPlayer(playerid, textDrawClock);

	return true;
}