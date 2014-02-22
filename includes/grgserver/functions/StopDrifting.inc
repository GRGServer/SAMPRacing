StopDrifting(playerID)
{
	PVar:playerID[DRIFTING_ANGLEBONUS] = 0;
	PVar:playerID[DRIFTING_BESTSCORE] = 0;
	PVar:playerID[DRIFTING_LASTSCORE] = 0;
	PVar:playerID[DRIFTING_MAXSCORE] = 0;
	PVar:playerID[DRIFTING_SCORE] = 0;
	PVar:playerID[DRIFTING_SCORESTATE] = false;
	PVar:playerID[DRIFTING_SPEEDBONUS] = 0;
	PVar:playerID[DRIFTING_STATE] = false;

	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_BONUS_VALUES]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_BOTTOM]);

	SendClientMessageEx(playerID, COLOR_INFO, StringID:32("Drifting has been disabled"));
}