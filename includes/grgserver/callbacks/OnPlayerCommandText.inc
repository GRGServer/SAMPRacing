public OnPlayerCommandText(playerid, cmdtext[])
{
	new cmdText[256];
	new command[MAX_FUNCTION_NAME];
	new parameters[256];

	strcat(cmdText, cmdtext);
	strdel(cmdText, 0, 1);// Remove the slash before the command
	if (sscanf(cmdText, "s[" #MAX_FUNCTION_NAME "]s[256]", command, parameters))
	{
		sscanf(cmdText, "s[" #MAX_FUNCTION_NAME "]", command);
	}

	printf("Player %s issued server command: %s", GetPlayerNameEx(playerid), cmdText);// Log executed command to console

	ExecuteCommand(playerid, command, parameters);
	return true;
}