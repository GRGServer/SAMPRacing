public OnPlayerConnect(playerid)
{
	ResetPlayerVariables(playerid);

	if (IsBanned(playerid, true))
	{
		Kick(playerid);
		return false;
	}
	
	printf("%s connected from %s", GetPlayerNameEx(playerid), GetPlayerCountryName(playerid));

	PlayerLoop(playerID)
	{
		if (!IsPlayerNPC(playerID) && playerID != playerid)
		{
			SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:23("%p has joined the server"), playerid);
		}
	}
	ShowDialog:PreviewInfo(playerid);
	return true;
}