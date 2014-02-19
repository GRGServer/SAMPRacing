CMD:drift(playerID, params[], StringID:48("Drifting ON/OFF"))
{
	if ((DriftingState[playerID] == false) && (IsPlayerInAnyVehicle(playerID)==1))
	{
		DriftingState[playerID]=true;
		SendClientMessageEx(playerID, COLOR_INFO, StringID:51("Driftmode ON"));
		TextDrawShowForPlayer(playerID,DrawScore[playerID]);
		TextDrawShowForPlayer(playerID,DrawLastScore[playerID]);
		TextDrawShowForPlayer(playerID,DrawBestScore[playerID]);
	}
	else if (DriftingState[playerID] == true)
	{
		CancelDrifting(playerID);
		SendClientMessageEx(playerID, COLOR_INFO, StringID:49("Driftmode OFF"));
	}
	if (IsPlayerInAnyVehicle(playerID)==0)
	{
		SendClientMessageEx(playerID, COLOR_ERROR, StringID:50("You are not in a Vehicle!"));
	}
	return COMMAND_OK;
}