public OnPlayerText(playerid, text[])
{
	mysql_query_format(false, "INSERT INTO `chatlog` (`userId`, `date`, `message`) VALUES(%d, NOW(), '%e')", PVar:playerid[USERID], text);

	FormatNew:message[256]("[%s] %s", GetPlayerNameEx(playerid), text);
	SendClientMessage(playerid, COLOR_CHAT, message);
	return false;
}