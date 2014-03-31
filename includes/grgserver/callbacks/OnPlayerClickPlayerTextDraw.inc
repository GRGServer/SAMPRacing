public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (playertextid == g_playerTextDraws[playerid][E_PTD_RACELOBBY_BUTTON_START])
	{
		new raceID = PVar:playerid[RACE_ID];

		if (g_races[raceID][E_RACE_HOSTPLAYERID] != playerid)
		{
			return false;
		}

		g_races[raceID][E_RACE_STARTED] = true;

		new players;
		PlayerLoop(playerID)
		{
			if (PVar:playerID[RACE_ID] == raceID && !IsPlayerNPC(playerID))
			{
				players++;

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

		new spawnIndex = RACE_PLAYERCOUNT - players;// 4 players = Start at 0, 3 players = Start at 1 (0 = NPC), 2 players = Start at 2 (0 - 1 = NPC), 1 player = Start at 3 (0 - 2 = NPC)
		PlayerLoop(playerID)
		{
			if (PVar:playerID[RACE_ID] == raceID && !IsPlayerNPC(playerID))
			{
				PVar:playerID[RACE_SPAWN] = spawnIndex;
				spawnIndex++;
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

		new raceID = PVar:playerid[RACE_ID];

		g_races[raceID][E_RACE_HOSTPLAYERID] = INVALID_PLAYER_ID;

		// Search for another host of the race
		PlayerLoop(playerID)
		{
			if (playerID != playerid && PVar:playerID[RACE_ID] == raceID && PVar:playerID[RACE_LOBBYUPDATETIMER])
			{
				g_races[raceID][E_RACE_HOSTPLAYERID] = playerID;

				FormatNew:string[100]("~n~~n~~n~~n~~n~~n~~n~~n~~n~%s", LanguageString(playerID, StringID:185("You are now the host of this race")));
				GameTextForPlayer(playerID, string, 3000, 3);

				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_START]);
				break;
			}
		}

		return true;
	}

	return false;
}