DisqualifyRacePlayer(playerID)
{
	FormatNew:string[100]("~r~%s", LanguageString(playerID, StringID:182("You got disqualified from the race!")));
	GameTextForPlayer(playerID, string, 3000, 3);

	DisablePlayerRaceCheckpoint(playerID);

	PVar:playerID[RACE_ID] = -1;
	PVar:playerID[RACE_STARTED] = false;

	PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_RACE_BOTTOM]);

	KillTimer(PVar:playerID[RACE_DISQUALIFY_TIMER]);
}