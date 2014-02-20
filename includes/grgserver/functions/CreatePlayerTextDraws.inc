CreatePlayerTextDraws(playerID)
{
	// Drifting Angle Bonus
	PTextDraw:playerID[DRIFTING_ANGLEBONUS] = CreatePlayerTextDraw(playerID, 110.000000, 425.000000, " ");
	PlayerTextDrawAlignment(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 3);
	PlayerTextDrawBackgroundColor(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 255);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 0.500000, 1.000000);
	PlayerTextDrawColor(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 16711935);
	PlayerTextDrawSetOutline(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 1);
	PlayerTextDrawSetProportional(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 1);
	PlayerTextDrawSetShadow(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS],1);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 1);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_ANGLEBONUS], 0x000000FF);

	// Drifting Best Score
	PTextDraw:playerID[DRIFTING_BESTSCORE] = CreatePlayerTextDraw(playerID, 290.000000, 411.000000, " ");
	PlayerTextDrawBackgroundColor(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 255);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 0.500000, 1.000000);
	PlayerTextDrawColor(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], -16776961);
	PlayerTextDrawSetOutline(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 1);
	PlayerTextDrawSetProportional(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 1);
	PlayerTextDrawSetShadow(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE],1);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 1);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_BESTSCORE], 0x000000FF);

	// Drifting Last Score
	PTextDraw:playerID[DRIFTING_LASTSCORE] = CreatePlayerTextDraw(playerID, 290.000000, 425.000000, " ");
	PlayerTextDrawBackgroundColor(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 255);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 0.500000, 1.000000);
	PlayerTextDrawColor(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], -16776961);
	PlayerTextDrawSetOutline(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 1);
	PlayerTextDrawSetProportional(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 1);
	PlayerTextDrawSetShadow(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE],1);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 1);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_LASTSCORE], 0x000000FF);

	// Drifting Score
	PTextDraw:playerID[DRIFTING_SCORE] = CreatePlayerTextDraw(playerID, 290.000000, 402.000000, " ");
	PlayerTextDrawBackgroundColor(playerID, PTextDraw:playerID[DRIFTING_SCORE], 255);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_SCORE], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_SCORE], 0.500000, 1.000000);
	PlayerTextDrawColor(playerID, PTextDraw:playerID[DRIFTING_SCORE], -16776961);
	PlayerTextDrawSetOutline(playerID, PTextDraw:playerID[DRIFTING_SCORE], 1);
	PlayerTextDrawSetProportional(playerID, PTextDraw:playerID[DRIFTING_SCORE], 1);
	PlayerTextDrawSetShadow(playerID, PTextDraw:playerID[DRIFTING_SCORE],1);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_SCORE], 1);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_SCORE], 0x000000FF);

	// Drifting Speed Bonus
	PTextDraw:playerID[DRIFTING_SPEEDBONUS] = CreatePlayerTextDraw(playerID, 456.000000, 425.000000, " ");
	PlayerTextDrawAlignment(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 3);
	PlayerTextDrawBackgroundColor(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 255);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 0.500000, 1.000000);
	PlayerTextDrawColor(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 16711935);
	PlayerTextDrawSetOutline(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 1);
	PlayerTextDrawSetProportional(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 1);
	PlayerTextDrawSetShadow(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS],1);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 1);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_SPEEDBONUS], 0x000000FF);
}