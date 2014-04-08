ShowDialog:CommandList(playerID)
{
	new list[2048];

	Foreach(index, g_commands)
	{
		if (StrNotNull(g_commands[index][E_COMMAND_NAME]))
		{
			// TODO: Make it dynamic
			if (IsStr(g_commands[index][E_COMMAND_PVARNAME], "ISADMIN") && !PVar:playerID[ISADMIN])
			{
				continue;
			}
			if (IsStr(g_commands[index][E_COMMAND_PVARNAME], "HAS_MOBILEVEHICLESHOP") && !PVar:playerID[HAS_MOBILEVEHICLESHOP])
			{
				continue;
			}

			ConcatString(list, g_commands[index][E_COMMAND_NAME], "\n");
		}
	}
	CreateDialog(playerID, "CommandList", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:218("Commands")), list, LanguageString(playerID, StringID:219("Details")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:CommandList(playerID, response, listItem, inputText[])
{
	if (response)
	{
		ShowDialog:CommandDetails(playerID, inputText);
	}
}