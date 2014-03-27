public OnGameModeExit()
{
	SaveAll();

	// Kick all NPCs
	PlayerLoop(playerID)
	{
		if (IsPlayerNPC(playerID))
		{
			Kick(playerID);
		}
	}

	mysql_close();
}