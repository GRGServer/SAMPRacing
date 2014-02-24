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
			new Cache:result = mysql_query_format(true, "SELECT `id` FROM `users` WHERE `username` = '%e' AND `password` = '%e'", GetPlayerNameEx(playerID), Hash(inputText));
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
			cache_delete(result);

			if (PVar:playerID[USERID])
			{
				// Update some stats
				mysql_query_format(false, "UPDATE `users` SET `lastLogin` = NOW() WHERE `id` = %d", PVar:playerID[USERID]);

				// Send login message to all players except the logged in player
				PlayerLoop(currentPlayerID)
				{
					if (currentPlayerID != playerID)
					{
						SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%u logged in"), playerID);
					}
				}

				// The next spawn is the first one
				PVar:playerID[SPAWNTYPE] = SPAWNTYPE_FIRSTSPAWN;

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