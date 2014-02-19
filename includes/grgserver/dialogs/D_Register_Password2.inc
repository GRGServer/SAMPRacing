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
			MySQLQuery("INSERT INTO `users` (`username`, `password`, `language`, `registerDate`, `lastLogin`) VALUES('%s', '%s', '%s', NOW(), NOW())", MySQLEscapeString(GetPlayerNameEx(playerID)), Hash(inputText), GetLanguageByID(PVar:playerID[LANGUAGE]));

			PVar:playerID[USERID] = mysql_insert_id();

			// Send login message to all players except the logged in player
			PlayerLoop(currentPlayerID)
			{
				if (currentPlayerID != playerID)
				{
					SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%p logged in"), playerID);
				}
			}

			// The next spawn is the first one
			PVar:playerID[FIRSTSPAWN] = true;

			// Load and spawn the player
			LoadPlayer(playerID);
			SpawnPlayer(playerID);

			SendClientMessageEx(playerID, COLOR_INFO, StringID:41("Your registration was successful"));
			SendClientMessageEx(playerID, COLOR_INFO, StringID:46("You are now logged in"));
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