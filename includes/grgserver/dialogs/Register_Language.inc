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
		// Save the selected language to the player variable
		new languageName[3];
		new languageTitle[100];
		sscanf(inputText, "p<\t>s[3]s[100]", languageName, languageTitle);
		PVar:playerID[LANGUAGE] = GetLanguageID(languageName);

		// Show the next dialog (request new password)
		ShowDialog:Register_Password1(playerID);
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_INFO, StringID:35("You can now quit the game"));
		Kick(playerID);
	}
}