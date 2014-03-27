Timer:RaceCountDown(raceID)
{
	PlayerLoop(playerID)
	{
		if (PVar:playerID[RACE_ID] == raceID)
		{
			new string[10];

			if (g_races[raceID][E_RACE_COUNTDOWN])
			{
				Format:string("~r~%d", g_races[raceID][E_RACE_COUNTDOWN]);
			}
			else
			{
				Format:string("~g~%s", LanguageString(playerID, StringID:186("Go!")));

				if (IsPlayerNPC(playerID))
				{
					SendNPCCommand(playerID, NPCCMD_START);
				}

				TogglePlayerControllable(playerID, true);
			}

			GameTextForPlayer(playerID, string, 3000, 6);
		}
	}

	if (!g_races[raceID][E_RACE_COUNTDOWN])
	{
		KillTimer(g_races[raceID][E_RACE_COUNTDOWNTIMER]);
		return;
	}

	g_races[raceID][E_RACE_COUNTDOWN]--;
}