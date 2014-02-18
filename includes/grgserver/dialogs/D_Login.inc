ShowDialog:Login(playerID)
{
	CreateDialog(playerID, "Login", DIALOG_STYLE_PASSWORD, "Login", LanguageString(playerID, StringID:24("Please enter the password of your account.")), "OK", LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:Login(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (strlen(inputText))
		{
			MySQLQuery("SELECT `id` FROM `users` WHERE `username` = '%s' AND `password` = '%s'", MySQLEscapeString(GetPlayerNameEx(playerID)), MD5(inputText));
			mysql_store_result();
			if (mysql_num_rows())
			{
				PVar:playerID[USERID] = strval(GetMySQLField("id"));
			}
			else
			{
				SendClientMessageEx(playerID, COLOR_ERROR, StringID:25("The entered password ist wrong!"));
				ShowDialog:Login(playerID);
			}
			mysql_free_result();
			if (PVar:playerID[USERID])
			{
				MySQLQuery("UPDATE `users` SET `loginTime` = NOW(), `clientVersion` = '%s' WHERE `id` = '%d'", GetPlayerVersionEx(playerID), PVar:playerID[USERID]);
				PlayerLoop(currentPlayerID)
				{
					if (currentPlayerID != playerID)
					{
						SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%p logged in"), playerID);
					}
				}
				LoadPlayer(playerID);
				SpawnPlayer(playerID);
				SendClientMessageEx(playerID, COLOR_INFO, StringID:27("You have been logged in successfully"));
			}
			else
			{
				SendClientMessageEx(playerID, COLOR_ERROR, StringID:29("You have to enter your password!"));
				ShowDialog:Login(playerID);
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
	return true;
}