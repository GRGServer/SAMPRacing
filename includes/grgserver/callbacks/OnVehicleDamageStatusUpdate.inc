public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	if (PVar:playerid[DRIFTING_STATE] && GetPlayerVehicleID(playerid) == vehicleid && GetPlayerVehicleSeat(playerid) == 0)
	{
		new panelsState;
		new doorsState;
		new lightsState;
		new tiresState;
		GetVehicleDamageStatus(vehicleid, panelsState, doorsState, lightsState, tiresState);
		if (panelsState || doorsState || lightsState || tiresState)
		{
			PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_SPEEDBONUS]);
			PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
			PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_ANGLEBONUS]);
			PVar:playerid[DRIFTING_ANGLEBONUS] = 0;

			PVar:playerid[DRIFTING_SCORE] = 0;
			new string[100];
			Format:string(LanguageString(playerid, StringID:47("Score: %d")), PVar:playerid[DRIFTING_SCORE]);
			PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_SCORE], string);
		}
	}
}