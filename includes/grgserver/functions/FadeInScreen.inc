FadeInScreen(playerID, steps)
{
	PVar:playerID[SCREENFADER_FADEOUT] = false;
	PVar:playerID[SCREENFADER_STEPS] = steps;

	if (PVar:playerID[SCREENFADER_TIMER])
	{
		KillTimer(PVar:playerID[SCREENFADER_TIMER]);
	}
	PVar:playerID[SCREENFADER_TIMER] = SetTimerEx("Timer_ScreenFader", TIMER_SCREENFADER, true, "d", playerID);
}