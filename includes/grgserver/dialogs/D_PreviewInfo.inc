ShowDialog:PreviewInfo(playerID)
{
	CreateDialog(playerID, "PreviewInfo", DIALOG_STYLE_MSGBOX, LanguageString(playerID, StringID:40("Preview")), LanguageString(playerID, StringID:41("This is Preview Server!")), "OK", "");
}

DialogResponse:PreviewInfo(playerID, response, listItem, inputText[])
{
	if (mysql_CheckAccount(playerID) == 0)
	{
		ShowDialog:Register_Password1(playerID);
	}
	else
	{
		ShowDialog:Login(playerID);
	}
}

stock mysql_CheckAccount(playerid)
{
	new Query[128],Name[MAX_PLAYER_NAME],count;
	GetPlayerName(playerid, Name, MAX_PLAYER_NAME);
	mysql_real_escape_string(Name, Name);
	format(Query, sizeof(Query), "SELECT * FROM `users` WHERE `username` = '%s'", Name);
	mysql_query(Query);
	mysql_store_result();
	count = mysql_num_rows();
	mysql_free_result();
	return count;
}