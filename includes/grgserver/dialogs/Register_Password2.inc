ShowDialog:Register_Password2(playerID)
{
	CreateDialog(playerID, "Register_Password2", DIALOG_STYLE_PASSWORD, LanguageString(playerID, StringID:39("Repeat password")), LanguageString(playerID, StringID:38("Please repeat your new password to verfify.")), LanguageString(playerID, StringID:37("Next")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:Register_Password2(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (!strcmp(inputText, PVar:playerID[REGISTERPASSWORD]))
		{
			// Add the new user to the database
			MySQLFormat("INSERT INTO `users` (`username`, `password`, `language`, `money`, `registerDate`, `lastLogin`) VALUES('%e', '%e', '%e', %d, NOW(), NOW())", GetPlayerNameEx(playerID), Hash(inputText), GetLanguageByID(PVar:playerID[LANGUAGE]), REGISTER_MONEY);
			mysql_pquery(1, g_sqlQuery, "OnPlayerRegistered", "d", playerID);
		}
		else
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:31("The entered passwords do not match! Please try again."));
			ShowDialog:Register_Password1(playerID);
		}
	}
	else
	{
		ShowDialog:Register_Password1(playerID);
	}
}