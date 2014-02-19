public OnPlayerUpdate(playerid)
{
	if (DriftingState[playerid] == true)
	{
		Drifting(playerid);
	}
	return true;
}