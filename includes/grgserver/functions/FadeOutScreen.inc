FadeOutScreen(playerID, steps, red, green, blue, id)
{
    PVar:playerID[SCREENFADER_FADEOUT] = true;
    PVar:playerID[SCREENFADER_ID] = id;
    PVar:playerID[SCREENFADER_STEPS] = steps;
    PVar:playerID[SCREENFADER_COLOR_RED] = red;
    PVar:playerID[SCREENFADER_COLOR_GREEN] = green;
    PVar:playerID[SCREENFADER_COLOR_BLUE] = blue;
    PVar:playerID[SCREENFADER_COLOR_ALPHA] = 0;

    if (PVar:playerID[SCREENFADER_TIMER])
    {
        KillTimer(PVar:playerID[SCREENFADER_TIMER]);
    }
    PVar:playerID[SCREENFADER_TIMER] = SetTimerEx:ScreenFader(TIMER_SCREENFADER, true, "d", playerID);
}