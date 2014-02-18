Timer:SpawnPlayer(playerID)
{
	SpawnPlayer(playerID);
	if (IsPlayerNPC(playerID))
	{
		return true;
	}
	TogglePlayerSpectating(playerID, true);

	MySQLQuery("SELECT * FROM `users` WHERE `username` = '%s'", MySQLEscapeString(GetPlayerNameEx(playerID)));
	mysql_store_result();
	if (strval(GetMySQLField("id")))
	{
		PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
		PVar:playerID[REGISTERED] = true;
		ShowDialog:PreviewInfo(playerID);
	}
	else
	{
		new countryCode[3];
		strcat(countryCode, GetPlayerCountryCode(playerID));
		if (strlen(countryCode) && (!strcmp(countryCode, "AT", true) || !strcmp(countryCode, "CH", true) || !strcmp(countryCode, "DE", true)))
		{
			PVar:playerID[LANGUAGE] = LANGUAGE_GERMAN;
		}
		else
		{
			PVar:playerID[LANGUAGE] = LANGUAGE_ENGLISH;
		}
		PVar:playerID[REGISTERED] = false;
		PlaySound(playerID, musicSoundIDs[random(sizeof(musicSoundIDs))]);
		ShowDialog:Register_Language(playerID);
	}
	mysql_free_result();
	SendClientMessageEx(playerID, COLOR_SYSTEM, StringID:32("Welcome to the GRG server!"));
	PlayerLoop(currentPlayerID)
	{
		if (!IsPlayerNPC(currentPlayerID) && currentPlayerID != playerID)
		{
			SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:23("%p has joined the server"), playerID);
		}
	}
	return true;
}