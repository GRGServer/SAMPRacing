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
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS] = CreatePlayerTextDraw(playerID, 480, 400, " ");
	PlayerTextDrawTextSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 640, 0);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], 0xff000066);

	// Drifting bonus values
	g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES] = CreatePlayerTextDraw(playerID, 580, 400, " ");
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], 0.4, 0.8);

	// Object editor info
	g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO] = CreatePlayerTextDraw(playerID, 320, 425, " ");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_OBJEDITOR_INFO], 0x00000066);

	// Show pos
	g_playerTextDraws[playerID][E_PTD_SHOWPOS] = CreatePlayerTextDraw(playerID, 10, 150, " ");
	PlayerTextDrawTextSize(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS], 150, 0);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_SHOWPOS], 0x00000066);

	// Vehicle info box
	g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS] = CreatePlayerTextDraw(playerID, 480, 300, " ");
	PlayerTextDrawTextSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS], 640, 0);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS], 0x00000066);

	// Vehicle info name
	g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME] = CreatePlayerTextDraw(playerID, 560, 300, " ");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME], 0.4, 0.8);

	// Vehicle info values
	g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES] = CreatePlayerTextDraw(playerID, 570, 300, " ");
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES], 0.4, 0.8);

	// Vehicle shop control info
	g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO] = CreatePlayerTextDraw(playerID, 500, 375, " ");
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], 0x00000066);

	// Vehicle shop vehicle info
	g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO] = CreatePlayerTextDraw(playerID, 320, 425, " ");
	PlayerTextDrawAlignment(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 2);
	PlayerTextDrawFont(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 1);
	PlayerTextDrawLetterSize(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 0.4, 0.8);
	PlayerTextDrawUseBox(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], true);
	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_VEHICLE_INFO], 0x00000066);

	UpdatePlayerTextDrawStrings(playerID);
}