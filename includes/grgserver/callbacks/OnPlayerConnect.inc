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
	new Cache:result = mysql_query_format(true, "SELECT `id`, `language` FROM `users` WHERE `username` = '%e'", GetPlayerNameEx(playerid));
	new rows = cache_get_row_count();
	if (rows)
	{
		PVar:playerid[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	}
	cache_delete(result);

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

	TextDrawShowForPlayer(playerid, g_textDrawClock);

	return true;
}