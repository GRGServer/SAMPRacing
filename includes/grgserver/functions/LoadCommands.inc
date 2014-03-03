LoadCommands()
{
	print("Loading command list...");

	new commandID;
	new item[100];
	new type;
	new RegEx:regex = regex_build("^(ACMD|CMD):([a-z]+)\\(playerID, params\\[\\], StringID:([0-9]+)\\(\"(.*)\"\\)\\)");
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
				regex_replace_exid(line, regex, "$1 $2 $3", lineReplaced);

				new commandType[5];
				new command[STRINGLENGTH_COMMANDNAME];
				new languageStringID;
				if (!sscanf(lineReplaced, "s[5]s[" #STRINGLENGTH_COMMANDNAME "]d", commandType, command, languageStringID))
				{
					if (commandID >= MAX_COMMANDS)
					{
						printf("  Reached limit of %d commands", MAX_COMMANDS);
						break;
					}

					g_commands[commandID][E_COMMAND_ADMIN] = !strcmp(commandType, "ACMD");
					g_commands[commandID][E_COMMAND_NAME] = command;
					g_commands[commandID][E_COMMAND_LANGUAGESTRINGID] = languageStringID;
					commandID++;
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

	SortDeepArray(g_commands, string:E_COMMAND_NAME);// TODO: Does not sort the array (See also http://forum.sa-mp.com/showpost.php?p=2937426&postcount=86)

	printf("  %d commands loaded", commandID);
}