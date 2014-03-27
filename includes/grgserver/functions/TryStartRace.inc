TryStartRace(raceID)
{
	PlayerLoop(playerID)
	{
		if (PVar:playerID[RACE_ID] == raceID && !PVar:playerID[RACE_READY])
		{
			return false;
		}
	}

	g_races[raceID][E_RACE_COUNTDOWN] = 3;

	g_races[raceID][E_RACE_COUNTDOWNTIMER] = SetTimerEx("Timer_RaceCountDown", 1000, true, "d", raceID);

	return true;
}