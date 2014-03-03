CMD:cmds(playerID, params[], StringID:123("List all available commands"))
{
	new string[256];

	Foreach(index, g_commands)
	{
		if (StrNotNull(g_commands[index][E_COMMAND_NAME]) && (PVar:playerID[ISADMIN] || !g_commands[index][E_COMMAND_ADMIN]))
		{
			Format:string("%s - %s", g_commands[index][E_COMMAND_NAME], LanguageString(playerID, g_commands[index][E_COMMAND_LANGUAGESTRINGID]));
			SendClientMessage(playerID, COLOR_INFO, string);
		}
	}

	return COMMAND_OK;
}