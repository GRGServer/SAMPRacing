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

		if (!IsPlayerNPC(playerid) && playerid != playerid)
		{
			SendClientMessageEx(playerid, COLOR_JOINLEAVE, StringID:22("%p has left the server (%s)"), playerid, reasonString);
		}
	}

	ResetPlayerVariables(playerid);
	
	// Player Drifting TextDraw
	
	CancelDrifting(playerid);
	DestroyTextDraw(playerid);

	return true;
}