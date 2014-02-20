public OnPlayerDeath(playerid, killerid, reason)
{
	if (PVar:playerid[DRIFTING_STATE])
	{
		StopDrifting(playerid);
	}
}