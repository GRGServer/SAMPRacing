public OnPlayerText(playerid, text[])
{
    MySQLFormat("INSERT INTO `chatlog` (`userId`, `date`, `message`) VALUES(%d, NOW(), '%e')", PVar:playerid[USERID], text);
    mysql_pquery(g_mysql, g_sqlQuery);

    FormatNew:message[256]("[%s] %s", GetPlayerNameEx(playerid), text);
    SendClientMessageToAll(COLOR_CHAT, message);
    return false;
}