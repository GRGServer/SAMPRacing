SetPrivateWorld(playerID, newState)
{
	if (newState)
	{
		SetPlayerVirtualWorld(playerID, playerID + 1);
	}
	else
	{
		SetPlayerVirtualWorld(playerID, 0);
	}
}