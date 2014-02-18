ShowDialog:Register_Language(playerID)
{
	new list[1024];
	AddLine(list, "en\tEnglish");
	AddLine(list, "de\tDeutsch");
	CreateDialog(playerID, "Register_Language", DIALOG_STYLE_LIST, "Select language / Sprache wählen", list, "OK", "Quit / Beenden");
}

DialogResponse:Register_Language(playerID, response, listItem, inputText[])
{
	if (response)
	{
		new languageName[3];
		new languageTitle[100];
		sscanf(inputText, "p<\t>s[3]s[100]", languageName, languageTitle);
		PVar:playerID[LANGUAGE] = GetLanguageID(languageName);
		MySQLQuery("INSERT INTO `users` (`username`, `password`, `language`, `register`) VALUES('%s', '%s', '%s', '1')", MySQLEscapeString(GetPlayerNameEx(playerID)), MD5(PVar:playerID[REGISTERPASSWORD]), MySQLEscapeString(PVar:playerID[LANGUAGE]));
		PVar:playerID[USERID] = mysql_insert_id();
		PVar:playerID[ONLINESINCE] = gettime();
		MySQLQuery("UPDATE `users` SET `registerTime` = NOW(), `loginTime` = NOW(), `clientVersion` = '%s' WHERE `id` = '%d'", MySQLEscapeString(GetPlayerVersionEx(playerID)), PVar:playerID[USERID]);
		SavePlayer(playerID);
		LoadPlayer(playerID);
		printf("Player registered: %s (UserID: %d)", GetPlayerNameEx(playerID), PVar:playerID[USERID]);
		PlayerLoop(currentPlayerID)
		{
			if (currentPlayerID != playerID)
			{
				SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%p logged in"), playerID);
			}
		}
		PlayerPlaySound(playerID, 1063, 0.0, 0.0, 0.0);
		SendClientMessageEx(playerID, COLOR_INFO, StringID:46("You were registered successfully and are now logged in."));
		SpawnPlayer(playerID);
	
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_INFO, StringID:35("You can now quit the game"));
		Kick(playerID);
	}
}