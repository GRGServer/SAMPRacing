CreateGlobalTextDraws(playerid)
{
	printf("* Creating Server wide TextDraws....");
	
	// TextDraw DriftPoints
	
	//Textdraw Drift
	DrawScore[playerid] = TextDrawCreate(484.000000, 102.000000, "Punkte: 0");
	TextDrawBackgroundColor(DrawScore[playerid], 255);
	TextDrawFont(DrawScore[playerid], 1);
	TextDrawLetterSize(DrawScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawScore[playerid], -16776961);
	TextDrawSetOutline(DrawScore[playerid], 1);
	TextDrawSetProportional(DrawScore[playerid], 1);

	DrawBestScore[playerid] = TextDrawCreate(484.000000, 122.000000, "Beste: 0");
	TextDrawBackgroundColor(DrawBestScore[playerid], 255);
	TextDrawFont(DrawBestScore[playerid], 1);
	TextDrawLetterSize(DrawBestScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawBestScore[playerid], -16776961);
	TextDrawSetOutline(DrawBestScore[playerid], 1);
	TextDrawSetProportional(DrawBestScore[playerid], 1);

	DrawLastScore[playerid] = TextDrawCreate(485.000000, 112.000000, "Letzte: 0");
	TextDrawBackgroundColor(DrawLastScore[playerid], 255);
	TextDrawFont(DrawLastScore[playerid], 1);
	TextDrawLetterSize(DrawLastScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawLastScore[playerid], -16776961);
	TextDrawSetOutline(DrawLastScore[playerid], 1);
	TextDrawSetProportional(DrawLastScore[playerid], 1);

	DrawSpeedBonus[playerid] = TextDrawCreate(606.000000, 133.000000, "Geschwindigkeits Bonus!");
	TextDrawAlignment(DrawSpeedBonus[playerid], 3);
	TextDrawBackgroundColor(DrawSpeedBonus[playerid], 255);
	TextDrawFont(DrawSpeedBonus[playerid], 1);
	TextDrawLetterSize(DrawSpeedBonus[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawSpeedBonus[playerid], 16711935);
	TextDrawSetOutline(DrawSpeedBonus[playerid], 1);
	TextDrawSetProportional(DrawSpeedBonus[playerid], 1);

	DrawAngleBonus[playerid] = TextDrawCreate(606.000000, 143.000000, "Winkel Bonus!");
	TextDrawAlignment(DrawAngleBonus[playerid], 3);
	TextDrawBackgroundColor(DrawAngleBonus[playerid], 255);
	TextDrawFont(DrawAngleBonus[playerid], 1);
	TextDrawLetterSize(DrawAngleBonus[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawAngleBonus[playerid], 16711935);
	TextDrawSetOutline(DrawAngleBonus[playerid], 1);
	TextDrawSetProportional(DrawAngleBonus[playerid], 1);
	
	
	//TextDraw Clock 

	textDrawClock = TextDrawCreate(547, 25, "_");
	TextDrawSetShadow(textDrawClock, 0);
	TextDrawSetOutline(textDrawClock, 2);
	TextDrawLetterSize(textDrawClock, 0.6, 1.8);
	TextDrawFont(textDrawClock, 3);
}
