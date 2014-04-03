Timer:RandomRaceLobbyCamera(playerID)
{
	// Show another random lobby camera if the player is still in the lobby
	if (PVar:playerID[RACE_LOBBYUPDATETIMER])
	{
		RandomRaceLobbyCamera(playerID);
	}
}