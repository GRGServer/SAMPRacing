public OnPlayerDeath(playerid, killerid, reason)
{
	if (DriftingState[playerid] == true)
	{
	    CancelDrifting(playerid);
	    SendClientMessage(playerid, 0xFFAAFFAA, "We don't want no dead people drifting 'round these parts");
	}
	return 1;
}