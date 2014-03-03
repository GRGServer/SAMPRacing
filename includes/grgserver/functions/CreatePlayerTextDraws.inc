CreatePlayerTextDraws(playerID)
{
	new text[256];

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

	// Object editor info
	g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO] = CreatePlayerTextDraw(playerID, 320, 425, " ");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 0x00000066);

	// Drifting bonus values
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES] = CreatePlayerTextDraw(playerID, 580, 400, " ");
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 0.4, 0.8);

	// Vehicle shop control info
	Format:text(LanguageString(playerID, StringID:78("Previous: %s~n~Next: %s~n~Buy: %s~n~Quit: %s")), GetGameTextKeyByID(KEY_VEHICLESHOP_PREVIOUS, false), GetGameTextKeyByID(KEY_VEHICLESHOP_NEXT, false), GetGameTextKeyByID(KEY_VEHICLESHOP_BUY, false), GetGameTextKeyByID(KEY_VEHICLESHOP_QUIT, false));
	g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO] = CreatePlayerTextDraw(playerID, 500, 375, text);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 0x00000066);

	// Vehicle shop vehicle info
	g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO] = CreatePlayerTextDraw(playerID, 320, 425, "");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 0x00000066);
}