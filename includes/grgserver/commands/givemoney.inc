ACMD:givemoney(playerID, params[], StringID:86("Give money to yourself"))
{
	new amount;
	if (sscanf(params, "d", amount))
	{
		CmdUsageMsg(playerID, "givemoney", "Amount");
		return COMMAND_USAGE;
	}

	GivePlayerMoney(playerID, amount);
	SendClientMessageEx(playerID, COLOR_INFO, StringID:87("You gave $%d to yourself"), amount);

	return COMMAND_OK;
}