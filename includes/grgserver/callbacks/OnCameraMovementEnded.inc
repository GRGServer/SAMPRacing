forward OnCameraMovementEnded(playerID, movementIndex);
public OnCameraMovementEnded(playerID, movementIndex)
{
	switch (g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_TYPE])
	{
		case CAMMOVEMENT_RACELOBBY:
		{
			// Show another random lobby camera if the player is still in the lobby
			if (PVar:playerID[RACE_LOBBYUPDATETIMER])
			{
				RandomRaceLobbyCamera(playerID);
			}
		}
	}
}