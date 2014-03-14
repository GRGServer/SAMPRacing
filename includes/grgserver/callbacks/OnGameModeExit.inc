public OnGameModeExit()
{
	SaveAll();

	mysql_close();
	
	for(new i=0; i<PLAYERS; i++)
    {
		TextDrawHideForPlayer(i, LBox[i]);
		TextDrawHideForPlayer(i, LLine1[i]);
		TextDrawHideForPlayer(i, LLine2[i]);
		TextDrawHideForPlayer(i, LLine3[i]);
		TextDrawHideForPlayer(i, LLine4[i]);
		TextDrawHideForPlayer(i, LCredits[i]);
		TextDrawHideForPlayer(i, Lmph[i]);
		TextDrawHideForPlayer(i, LFunc[i]);
	}
}