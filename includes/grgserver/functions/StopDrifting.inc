StopDrifting(playerID)
{
	PVar:playerID[DRIFTING_SCORE] = 0;
	PVar:playerID[DRIFTING_ABSMAXSCORE] = 0;
	PVar:playerID[DRIFTING_ANGLEBONUS] = 0;
	PVar:playerID[DRIFTING_MAXSCORE] = 0;
	PVar:playerID[DRIFTING_SCORE] = 0;
	PVar:playerID[DRIFTING_SCORESTATE] = false;
	PVar:playerID[DRIFTING_SPEEDBONUS] = 0;
	PVar:playerID[DRIFTING_STATE] = false;

	SendClientMessageEx(playerID, COLOR_INFO, StringID:32("Drifting has been disabled"));

	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_SCORE]);
	PlayerTextDrawHide(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS]);
}