ShowDialog:Login(playerID)
{
	CreateDialog(playerID, "Login", DIALOG_STYLE_PASSWORD, LanguageString(playerID, StringID:45("Login")), LanguageString(playerID, StringID:24("Please enter the password of your account.")), LanguageString(playerID, StringID:40("OK")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:Login(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (strlen(inputText))
		{
			// Search user in database and compare password
			MySQLFormat("SELECT `id` FROM `users` WHERE `username` = '%e' AND `password` = '%e'", GetPlayerNameEx(playerID), Hash(inputText));
			mysql_pquery(1, g_sqlQuery, "OnPlayerLogin", "d", playerID);
		}
		else
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:29("You have to enter your password!"));
			ShowDialog:Login(playerID);
		}
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_INFO, StringID:28("You can now Quit the Game!"));
		Kick(playerID);
	}
}