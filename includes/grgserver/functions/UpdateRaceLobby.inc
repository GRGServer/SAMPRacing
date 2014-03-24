UpdateRaceLobby(playerID)
{
	new playerList[1024];
	new vehicleList[1024];
	new levelList[1024];

	PlayerLoop(currentPlayerID)
	{
		if (PVar:currentPlayerID[RACE_ID] == PVar:playerID[RACE_ID])
		{
			new vehicleModelID = GetVehicleModel(PVar:currentPlayerID[RACE_VEHICLEID]);
			if (vehicleModelID)
			{
				ConcatString(vehicleList, g_vehicleModels[vehicleModelID - 400][E_VEHICLEMODEL_NAME], "~n~");
			}
			else
			{
				ConcatString(vehicleList, "", "~n~");
			}

			ConcatString(playerList, GetPlayerNameEx(currentPlayerID), "~n~");

			if (strlen(levelList))
			{
				strcat(levelList, "~n~");
			}
			Format:levelList("%s%d", levelList, GetPlayerScore(currentPlayerID));
		}
	}

	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_PLAYERLIST], playerList);
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_VEHICLELIST], vehicleList);
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_LEVELLIST], levelList);
}