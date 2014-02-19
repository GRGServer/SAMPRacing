CreateGlobalTextDraws(playerid)
{
	printf("* Creating Server wide TextDraws....");
	
	// TextDraw DriftPoints
	
	//Textdraw Drift
	DrawScore[playerid] = TextDrawCreate(290.000000, 402.000000, "Punkte: 0");
	TextDrawBackgroundColor(DrawScore[playerid], 255);
	TextDrawFont(DrawScore[playerid], 1);
	TextDrawLetterSize(DrawScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawScore[playerid], -16776961);
	TextDrawSetOutline(DrawScore[playerid], 1);
	TextDrawSetProportional(DrawScore[playerid], 1);
	TextDrawSetShadow(DrawScore[playerid],1);
	TextDrawUseBox(DrawScore[playerid], 1);
	TextDrawBoxColor(DrawScore[playerid], 0x000000FF);

	DrawBestScore[playerid] = TextDrawCreate(290.000000, 411.000000, "Beste: 0");
	TextDrawBackgroundColor(DrawBestScore[playerid], 255);
	TextDrawFont(DrawBestScore[playerid], 1);
	TextDrawLetterSize(DrawBestScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawBestScore[playerid], -16776961);
	TextDrawSetOutline(DrawBestScore[playerid], 1);
	TextDrawSetProportional(DrawBestScore[playerid], 1);
	TextDrawSetShadow(DrawBestScore[playerid],1);
	TextDrawUseBox(DrawBestScore[playerid], 1);
	TextDrawBoxColor(DrawBestScore[playerid], 0x000000FF);



	DrawLastScore[playerid] = TextDrawCreate(290.000000, 425.000000, "Letzte: 0");
	TextDrawBackgroundColor(DrawLastScore[playerid], 255);
	TextDrawFont(DrawLastScore[playerid], 1);
	TextDrawLetterSize(DrawLastScore[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawLastScore[playerid], -16776961);
	TextDrawSetOutline(DrawLastScore[playerid], 1);
	TextDrawSetProportional(DrawLastScore[playerid], 1);
	TextDrawSetShadow(DrawLastScore[playerid],1);
	TextDrawUseBox(DrawLastScore[playerid], 1);
	TextDrawBoxColor(DrawLastScore[playerid], 0x000000FF);



	DrawSpeedBonus[playerid] = TextDrawCreate(456.000000, 425.000000, "Geschwindigkeits Bonus!");
	TextDrawAlignment(DrawSpeedBonus[playerid], 3);
	TextDrawBackgroundColor(DrawSpeedBonus[playerid], 255);
	TextDrawFont(DrawSpeedBonus[playerid], 1);
	TextDrawLetterSize(DrawSpeedBonus[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawSpeedBonus[playerid], 16711935);
	TextDrawSetOutline(DrawSpeedBonus[playerid], 1);
	TextDrawSetProportional(DrawSpeedBonus[playerid], 1);
	TextDrawSetShadow(DrawSpeedBonus[playerid],1);
	TextDrawUseBox(DrawSpeedBonus[playerid], 1);
	TextDrawBoxColor(DrawSpeedBonus[playerid], 0x000000FF);



	DrawAngleBonus[playerid] = TextDrawCreate(110.000000, 425.000000, "Winkel Bonus!");
	TextDrawAlignment(DrawAngleBonus[playerid], 3);
	TextDrawBackgroundColor(DrawAngleBonus[playerid], 255);
	TextDrawFont(DrawAngleBonus[playerid], 1);
	TextDrawLetterSize(DrawAngleBonus[playerid], 0.500000, 1.000000);
	TextDrawColor(DrawAngleBonus[playerid], 16711935);
	TextDrawSetOutline(DrawAngleBonus[playerid], 1);
	TextDrawSetProportional(DrawAngleBonus[playerid], 1);
	TextDrawSetShadow(DrawAngleBonus[playerid],1);
	TextDrawUseBox(DrawAngleBonus[playerid], 1);
	TextDrawBoxColor(DrawAngleBonus[playerid], 0x000000FF);


	
	
	//TextDraw Clock 

	textDrawClock = TextDrawCreate(547, 25, "_");
	TextDrawSetShadow(textDrawClock, 0);
	TextDrawSetOutline(textDrawClock, 2);
	TextDrawLetterSize(textDrawClock, 0.6, 1.8);
	TextDrawFont(textDrawClock, 3);
}
