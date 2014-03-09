PCMD:setobjectfilename[ISADMIN](playerID, params[], StringID:107("Specify the filename for new objects"))
{
	new filename[STRINGLENGTH_OBJECTFILENAME];
	if (sscanf(params, "s[" #STRINGLENGTH_OBJECTFILENAME "]", filename))
	{
		CmdUsageMsg(playerID, "setobjectfilename", "Filename");
		return COMMAND_USAGE;
	}

	PVar:playerID[OBJEDITOR_FILENAME] = filename;

	SendClientMessageEx(playerID, COLOR_INFO, StringID:108("The filename has been changed to '%s'"), PVar:playerID[OBJEDITOR_FILENAME]);
	return COMMAND_OK;
}