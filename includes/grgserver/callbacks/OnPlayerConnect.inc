public OnPlayerConnect(playerid)
{
	// Reset all player variables to their default values
	ResetPlayerVariables(playerid);

	if (IsPlayerNPC(playerid))
	{
		return true;
	}

	printf("%s connected from %s", GetPlayerNameEx(playerid), GetPlayerCountryName(playerid));

	SendDeathMessage(INVALID_PLAYER_ID, playerid, ICON_CONNECT);

	// Send join message to all players except the joined player
	PlayerLoop(playerID)
	{
		if (!IsPlayerNPC(playerID) && playerID != playerid)
		{
			SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:23("%u has joined the server"), playerid);
		}
	}

	// Remove standard objects
	RemoveStandardObjectsForPlayer(playerid);

	// Check whether the player is already registered
	MySQLFormat("SELECT `id`, `language` FROM `users` WHERE `username` = '%e'", GetPlayerNameEx(playerid));
	mysql_pquery(1, g_sqlQuery, "OnPlayerRegisteredCheck", "d", playerid);

	TextDrawShowForPlayer(playerid, g_textDrawClock);

	return true;
}