public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (playertextid == g_playerTextDraws[playerid][E_PTD_RACELOBBY_BUTTON_START])
	{
		if (g_races[PVar:playerid[RACE_ID]][E_RACE_HOSTPLAYERID] != playerid)
		{
			return false;
		}

		PlayerLoop(playerID)
		{
			if (PVar:playerID[RACE_ID] == PVar:playerid[RACE_ID])
			{
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BACKGROUND]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_TITLE]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER1]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER2]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER3]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_PLAYERLIST]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_VEHICLELIST]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_LEVELLIST]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_START]);
				PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_LEAVE]);

				CancelSelectTextDraw(playerID);

				FadeOutScreen(playerID, 5, 0, 0, 0, SCREENFADER_RACE_START);
			}
		}

		return true;
	}
	else if (playertextid == g_playerTextDraws[playerid][E_PTD_RACELOBBY_BUTTON_LEAVE])
	{
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_BACKGROUND]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_TITLE]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_HEADER1]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_HEADER2]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_HEADER3]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_PLAYERLIST]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_VEHICLELIST]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_LEVELLIST]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_BUTTON_START]);
		PlayerTextDrawHide(playerid, g_playerTextDraws[playerid][E_PTD_RACELOBBY_BUTTON_LEAVE]);

		CancelSelectTextDraw(playerid);

		FadeOutScreen(playerid, 5, 0, 0, 0, SCREENFADER_RACE_LEAVELOBBY);

		return true;
	}

	return false;
}