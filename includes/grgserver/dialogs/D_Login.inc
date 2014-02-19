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
			MySQLQuery("SELECT `id` FROM `users` WHERE `username` = '%s' AND `password` = '%s'", MySQLEscapeString(GetPlayerNameEx(playerID)), Hash(inputText));
			mysql_store_result();
			if (mysql_num_rows())
			{
				PVar:playerID[USERID] = strval(GetMySQLField("id"));
			}
			else
			{
				SendClientMessageEx(playerID, COLOR_ERROR, StringID:25("The entered password is wrong!"));
				ShowDialog:Login(playerID);
				return;
			}
			mysql_free_result();

			if (PVar:playerID[USERID])
			{
				// Update some stats
				MySQLQuery("UPDATE `users` SET `lastLogin` = NOW() WHERE `id` = '%d'", PVar:playerID[USERID]);

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

				SendClientMessageEx(playerID, COLOR_INFO, StringID:27("You have been logged in successfully"));
			}
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