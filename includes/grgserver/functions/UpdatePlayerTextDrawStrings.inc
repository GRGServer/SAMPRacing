UpdatePlayerTextDrawStrings(playerID)
{
	new string[256];

	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS], LanguageString(playerID, StringID:47("Speed bonus:~n~~n~Angle bonus:")));

	Format:string(LanguageString(playerID, StringID:154("Previous: %s~n~Next: %s~n~Spawn: %s~n~Quit: %s")), GetGameTextKeyByID(KEY_GARAGE_PREVIOUS, true), GetGameTextKeyByID(KEY_GARAGE_NEXT, true), GetGameTextKeyByID(KEY_GARAGE_GET, true), GetGameTextKeyByID(KEY_GARAGE_QUIT, true));
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_GARAGE_CTRL_INFO], string);

	Format:string(LanguageString(playerID, StringID:78("Previous: %s~n~Next: %s~n~Buy: %s~n~Quit: %s")), GetGameTextKeyByID(KEY_VEHICLESHOP_PREVIOUS, true), GetGameTextKeyByID(KEY_VEHICLESHOP_NEXT, true), GetGameTextKeyByID(KEY_VEHICLESHOP_BUY, true), GetGameTextKeyByID(KEY_VEHICLESHOP_QUIT, true));
	PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLESHOP_CTRL_INFO], string);
}