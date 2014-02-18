SetPlayerMoney(playerID, type, Float:amount, add = false)
{
	switch (type)
	{
		case MONEY_CASH:
		{
			if (add)
			{
				PVar:playerID[MONEY] = PVar:playerID[MONEY] + amount;
			}
			else
			{
				PVar:playerID[MONEY] = amount;
			}
			if (PVar:playerID[MONEY] > MAX_MONEY)
			{
				PVar:playerID[MONEY] = MAX_MONEY;
				SendClientMessageEx(playerID, COLOR_ERROR, StringID:45("You have exceeded the cash limit of %m!"), MAX_MONEY);
				printf("%s reached MAX_MONEY (%2f)", GetPlayerNameEx(playerID), MAX_MONEY);
			}
			ResetPlayerMoney(playerID);
			GivePlayerMoney(playerID, floatround(PVar:playerID[MONEY] * 100, floatround_tozero));
			return true;
		}
	}
	return false;
}