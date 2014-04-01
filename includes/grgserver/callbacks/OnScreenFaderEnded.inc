forward OnScreenFaderEnded(playerID);
public OnScreenFaderEnded(playerID)
{
	if (PVar:playerID[SCREENFADER_FADEOUT])
	{
		switch (PVar:playerID[SCREENFADER_ID])
		{
			case SCREENFADER_RACE_ENTERLOBBY:
			{
				TogglePlayerSpectating(playerID, true);

				new raceID = PVar:playerID[RACE_ID];

				PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_TITLE], g_races[raceID][E_RACE_NAME]);

				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BACKGROUND]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_TITLE]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER1]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER2]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_HEADER3]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_PLAYERLIST]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_VEHICLELIST]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_LEVELLIST]);
				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_LEAVE]);

				if (g_races[raceID][E_RACE_HOSTPLAYERID] == INVALID_PLAYER_ID)
				{
					g_races[raceID][E_RACE_HOSTPLAYERID] = playerID;

					PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_START]);
				}

				UpdateRaceLobby(playerID);
				PVar:playerID[RACE_LOBBYUPDATETIMER] = SetTimerEx("Timer_UpdateRaceLobby", TIMER_UPDATERACELOBBY, true, "d", playerID);

				FadeInScreen(playerID, 5, SCREENFADER_RACE_ENTERLOBBY);
			}
			case SCREENFADER_RACE_LEAVELOBBY:
			{
				PVar:playerID[SPAWN_TYPE] = SPAWNTYPE_LEAVERACE;

				KillTimer(PVar:playerID[RACE_LOBBYUPDATETIMER]);
				PVar:playerID[RACE_LOBBYUPDATETIMER] = 0;

				TogglePlayerSpectating(playerID, false);

				PVar:playerID[RACE_ID] = -1;
				PVar:playerID[ALLOWCMDS] = true;
			}
			case SCREENFADER_RACE_START:
			{
				new raceID = PVar:playerID[RACE_ID];
				new spawn = PVar:playerID[RACE_SPAWN];

				SetPlayerSpawn(playerID, SPAWNTYPE_STARTRACE, g_races[raceID][E_RACE_SPAWN_POSX][spawn], g_races[raceID][E_RACE_SPAWN_POSY][spawn], g_races[raceID][E_RACE_SPAWN_POSZ][spawn], g_races[raceID][E_RACE_SPAWN_ANGLE][spawn], 0);

				KillTimer(PVar:playerID[RACE_LOBBYUPDATETIMER]);
				PVar:playerID[RACE_LOBBYUPDATETIMER] = 0;

				TogglePlayerSpectating(playerID, false);
			}
			case SCREENFADER_TELEPORT:
			{
				TeleportTo(playerID, PVar:playerID[TELEPORTID], true);
			}
		}
	}
	else
	{
		switch (PVar:playerID[SCREENFADER_ID])
		{
			case SCREENFADER_RACE_ENTERLOBBY:
			{
				SelectTextDraw(playerID, COLOR_TEXTDRAWHOVER);
			}
			case SCREENFADER_RACE_START:
			{
				PVar:playerID[RACE_READY] = true;

				TryStartRace(PVar:playerID[RACE_ID]);
			}
			case SCREENFADER_TELEPORT:
			{
				TogglePlayerControllable(playerID, true);
			}
		}
	}
}