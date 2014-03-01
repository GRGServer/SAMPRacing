public OnPlayerDisconnect(playerid, reason)
{
	if (IsPlayerNPC(playerid))
	{
		ResetPlayerVariables(playerid);

		return true;
	}

	SavePlayer(playerid);

	SendDeathMessage(INVALID_PLAYER_ID, playerid, ICON_DISCONNECT);

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

	// Send leave message to all players except the leaving player
	PlayerLoop(playerID)
	{
		if (!IsPlayerNPC(playerID) && playerID != playerid)
		{
			SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:22("%u has left the server (%s)"), playerid, reasonString);
		}
	}

	ResetPlayerVariables(playerid);

	return true;
}