ShowDialog:CommandDetails(playerID, command[])
{
    format(PVar:playerID[COMMAND], STRINGLENGTH_COMMANDNAME, "%s", command);

    FormatNew:caption[100]("%s - %s", LanguageString(playerID, StringID:220("Command details")), command);

    new commandIndex = -1;
    Foreach(index, g_commands)
    {
        if (IsStr(g_commands[index][E_COMMAND_NAME], command))
        {
            commandIndex = index;
            break;
        }
    }

    if (commandIndex == -1)
    {
        return;
    }

    new content[2048];

    strcat(content, LanguageString(playerID, g_commands[commandIndex][E_COMMAND_LANGUAGESTRINGID]));
    strcat(content, "\n\n");
    strcat(content, LanguageString(playerID, StringID:222("Enter the command parameters bellow (if required)")));

    CreateDialog(playerID, "CommandDetails", DIALOG_STYLE_INPUT, caption, content, LanguageString(playerID, StringID:221("Execute")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:CommandDetails(playerID, response, listItem, inputText[])
{
    if (response)
    {
        ExecuteCommand(playerID, PVar:playerID[COMMAND], inputText);
    }
    else
    {
        ShowDialog:CommandList(playerID);
    }
}