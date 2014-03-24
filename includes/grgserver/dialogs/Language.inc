ShowDialog:Language(playerID)
{
	new list[1024];
	ConcatString(list, "en\tEnglish", "\n");
	ConcatString(list, "de\tDeutsch", "\n");
	CreateDialog(playerID, "Language", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:151("Select language")), list, LanguageString(playerID, StringID:40("OK")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:Language(playerID, response, listItem, inputText[])
{
	if (response)
	{
		// Save the selected language to the player variable
		new languageName[3];
		new languageTitle[100];
		sscanf(inputText, "p<\t>s[3]s[100]", languageName, languageTitle);
		PVar:playerID[LANGUAGE] = GetLanguageID(languageName);

		MySQLFormat("UPDATE `users` SET `language` = '%s' WHERE `id` = %d", GetLanguageByID(PVar:playerID[LANGUAGE]), PVar:playerID[USERID]);
		mysql_pquery(1, g_sqlQuery);

		UpdatePlayerTextDrawStrings(playerID);

		SendClientMessageEx(playerID, COLOR_INFO, StringID:152("The language has been changed"));
	}
}