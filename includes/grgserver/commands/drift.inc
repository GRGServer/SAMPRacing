CMD:drift(playerID, params[], StringID:48("Enable or disable drifting"))
{
	if (!IsPlayerInAnyVehicle(playerID))
	{
		return COMMAND_NOT_IN_VEHICLE;
	}

	if (GetPlayerVehicleSeat(playerID) != 0)
	{
		return COMMAND_NOT_VEHICLE_DRIVER;
	}

	if (PVar:playerID[DRIFTING_STATE])
	{
		StopDrifting(playerID);
	}
	else
	{
		PVar:playerID[DRIFTING_STATE] = true;

		PlayerTextDrawShow(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS]);
		PlayerTextDrawShow(playerID, PTextDraw:playerID[DRIFTING_BONUS_VALUES]);
		PlayerTextDrawShow(playerID, PTextDraw:playerID[DRIFTING_BOTTOM]);

		SendClientMessageEx(playerID, COLOR_INFO, StringID:42("Drifting has been enabled"));
	}

	return COMMAND_OK;
}