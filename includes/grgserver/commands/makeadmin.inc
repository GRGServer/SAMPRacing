ACMD:makeadmin(playerID, params[], StringID:51("Give admin privileges to another player"))
{
	new targetPlayerID;
	if (sscanf(params, "u", targetPlayerID))
	{
		CmdUsageMsg(playerID, "makeadmin", "PlayerID/Name");
		return COMMAND_USAGE;
	}

	PVar:targetPlayerID[ISADMIN] = true;

	mysql_query_format(false, "UPDATE `users` SET `isAdmin` = '1' WHERE `id` = %d", PVar:targetPlayerID[USERID]);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:52("You gave admin privileges to %u"), targetPlayerID);
	SendClientMessageEx(targetPlayerID, COLOR_INFO, StringID:53("You got admin privileges from %u"), playerID);

	return COMMAND_OK;
}