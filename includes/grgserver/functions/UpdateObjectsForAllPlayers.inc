UpdateObjectsForAllPlayers()
{
	PlayerLoop(playerID)
	{
		Streamer_Update(playerID);
	}
}