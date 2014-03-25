PCMD:connectnpc[ISADMIN](playerID, params[], StringID:188("Connect a new NPC"))
{
	new nameSuffix[MAX_PLAYER_NAME];
	if (sscanf(params, "s[128]", nameSuffix))
	{
		CmdUsageMsg(playerID, "connectnpc", "Suffix");
		return COMMAND_USAGE;
	}

	FormatNew:name[MAX_PLAYER_NAME]("NPC_%d_%s", playerID, nameSuffix);
	ConnectNPC(name, NPC_SCRIPT_NAME);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:189("The NPC '%s' will now try to connect"), name);
	return COMMAND_OK;
}