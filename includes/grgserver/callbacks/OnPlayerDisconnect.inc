public OnPlayerDisconnect(playerid, reason)
{
	if (IsPlayerNPC(playerid))
	{
		return true;
	}
	else
	{
		if (reason == 1)
		{
			SavePlayer(playerid);
		}

		new reasonString[16];
		switch (reason)
		{
			case 0:
			{
				strcat(reasonString, "Timed out");
			}
			case 1:
			{
				strcat(reasonString, "Leaving");
			}
			case 2:
			{
				strcat(reasonString, "Kicked/Banned");
			}
		}

		PlayerLoop(playerID)
		{
			if (!IsPlayerNPC(playerID) && playerID != playerid)
			{
				SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:22("%p has left the server (%s)"), playerid, reasonString);
			}
		}
	}

	ResetPlayerVariables(playerid);

	return true;
}