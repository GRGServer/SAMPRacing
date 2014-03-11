GetPlayerIDByUserID(userID)
{
	PlayerLoop(playerID)
	{
		if (PVar:playerID[USERID] == userID)
		{
			return playerID;
		}
	}

	return INVALID_PLAYER_ID;
}