LoadCommands()
{
	print("Loading command list...");

	new commandID;
	new item[100];
	new type;
	new RegEx:regex = regex_build("^(PCMD|CMD):([a-z]+)(\\[([A-Z_]+)\\])?\\(playerID, params\\[\\], StringID:([0-9]+)\\(\"(.*)\"\\)\\)");
	new dir:dirHandle = dir_open("includes/grgserver/commands");
	while (dir_list(dirHandle, item, type))
	{
		if (type == FM_FILE)
		{
			FormatNew:filename[100]("includes/grgserver/commands/%s", item);
			new File:file = f_open(filename, "r");
			new line[256];
			f_read(file, line);
			if (regex_match_exid(line, regex))
			{
				new lineReplaced[256];
				regex_replace_exid(line, regex, "$2 $4 $5", lineReplaced);

				new command[STRINGLENGTH_COMMANDNAME];
				new pVarName[32];
				new languageStringID;
				if (!sscanf(lineReplaced, "s[" #STRINGLENGTH_COMMANDNAME "]s[32]d", command, pVarName, languageStringID) || !sscanf(lineReplaced, "s[" #STRINGLENGTH_COMMANDNAME "]d", command, languageStringID))
				{
					if (commandID >= MAX_COMMANDS)
					{
						printf("  Reached limit of %d commands", MAX_COMMANDS);
						break;
					}

					g_commands[commandID][E_COMMAND_NAME] = command;
					g_commands[commandID][E_COMMAND_PVARNAME] = pVarName;
					g_commands[commandID][E_COMMAND_LANGUAGESTRINGID] = languageStringID;
					commandID++;
				}
				else
				{
					printf("  Can not parse first line in '%s'", item);
				}
			}
			else
			{
				printf("  Can not parse first line in '%s'", item);
			}
			f_close(file);
		}
	}
	regex_delete(regex);

	SortDeepArray(g_commands, String:E_COMMAND_NAME);// TODO: Fix warnings (tag mismatch)

	printf("  %d commands loaded", commandID);
}