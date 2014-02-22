CreatePlayerTextDraws(playerID)
{
	// Drifting bottom line
	PTextDraw:playerID[DRIFTING_BOTTOM] = CreatePlayerTextDraw(playerID, 320, 425, " ");
	PlayerTextDrawAlignment(playerID, PTextDraw:playerID[DRIFTING_BOTTOM], 2);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_BOTTOM], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_BOTTOM], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_BOTTOM], true);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_BOTTOM], 0x00000066);

	// Drifting bonus box
	PTextDraw:playerID[DRIFTING_BONUS_LABELS] = CreatePlayerTextDraw(playerID, 480, 400, LanguageString(playerID, StringID:47("Speed bonus:~n~~n~Angle bonus:")));
	PlayerTextDrawTextSize(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS], 640, 0);
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS], true);
	PlayerTextDrawBoxColor(playerID, PTextDraw:playerID[DRIFTING_BONUS_LABELS], 0xff000066);

	// Drifting bonus values
	PTextDraw:playerID[DRIFTING_BONUS_VALUES] = CreatePlayerTextDraw(playerID, 580, 400, " ");
	PlayerTextDrawFont(playerID, PTextDraw:playerID[DRIFTING_BONUS_VALUES], 1);
	PlayerTextDrawLetterSize(playerID, PTextDraw:playerID[DRIFTING_BONUS_VALUES], 0.4, 0.8);
}