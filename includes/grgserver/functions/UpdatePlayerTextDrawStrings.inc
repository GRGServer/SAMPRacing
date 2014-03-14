UpdatePlayerTextDrawStrings(playerID)
{
	new string[256];

	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], LanguageString(playerID, StringID:47("Speed bonus:~n~~n~Angle bonus:")));

	Format:string(LanguageString(playerID, StringID:78("Previous: %s~n~Next: %s~n~Buy: %s~n~Quit: %s")), GetGameTextKeyByID(KEY_VEHICLESHOP_PREVIOUS, false), GetGameTextKeyByID(KEY_VEHICLESHOP_NEXT, false), GetGameTextKeyByID(KEY_VEHICLESHOP_BUY, false), GetGameTextKeyByID(KEY_VEHICLESHOP_QUIT, false));
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], string);
}