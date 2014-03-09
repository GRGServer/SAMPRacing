PCMD:makeadmin[ISADMIN](playerID, params[], StringID:51("Give admin privileges to another player"))
{
	new targetPlayerID;
	if (sscanf(params, "u", targetPlayerID))
	{
		CmdUsageMsg(playerID, "makeadmin", "PlayerID/Name");
		return COMMAND_USAGE;
	}

	PVar:targetPlayerID[ISADMIN] = true;

	MySQLFormat("UPDATE `users` SET `isAdmin` = %d WHERE `id` = %d", PVar:targetPlayerID[ISADMIN], PVar:targetPlayerID[USERID]);
	mysql_pquery(1, g_sqlQuery);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:52("You gave admin privileges to %u"), targetPlayerID);
	SendClientMessageEx(targetPlayerID, COLOR_INFO, StringID:53("You got admin privileges from %u"), playerID);

	return COMMAND_OK;
}