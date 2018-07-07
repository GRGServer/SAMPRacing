Timer:ResetDriftingStats(playerID)
{
    PVar:playerID[DRIFTING_ANGLEBONUS] = 0;
    PVar:playerID[DRIFTING_BESTSCORE] = 0;
    PVar:playerID[DRIFTING_LASTSCORE] = 0;
    PVar:playerID[DRIFTING_MAXSCORE] = 0;
    PVar:playerID[DRIFTING_SCORE] = 0;
    PVar:playerID[DRIFTING_SCORESTATE] = false;
    PVar:playerID[DRIFTING_SPEEDBONUS] = 0;
}