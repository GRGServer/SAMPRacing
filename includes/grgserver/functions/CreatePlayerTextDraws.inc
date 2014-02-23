CreatePlayerTextDraws(playerID)
{
	// Drifting bottom line
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM] = CreatePlayerTextDraw(playerID, 320, 425, " ");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], 0x00000066);

	// Drifting bonus box
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS] = CreatePlayerTextDraw(playerID, 480, 400, LanguageString(playerID, StringID:47("Speed bonus:~n~~n~Angle bonus:")));
	PlayerTextDrawTextSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 640, 0);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 0xff000066);

	// Drifting bonus values
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES] = CreatePlayerTextDraw(playerID, 580, 400, " ");
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 0.4, 0.8);
}