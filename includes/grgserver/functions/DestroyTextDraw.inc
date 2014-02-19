DestroyTextDraw(playerid)
{
	SetPVarInt(playerid, "AbsMaxScore", 0);
	TextDrawHideForAll(DrawScore[playerid]);
	TextDrawDestroy(DrawScore[playerid]);
	TextDrawHideForAll(DrawBestScore[playerid]);
	TextDrawDestroy(DrawBestScore[playerid]);
	TextDrawHideForAll(DrawLastScore[playerid]);
	TextDrawDestroy(DrawLastScore[playerid]);
	TextDrawHideForAll(DrawAngleBonus[playerid]);
	TextDrawDestroy(DrawAngleBonus[playerid]);
	TextDrawHideForAll(DrawSpeedBonus[playerid]);
	TextDrawDestroy(DrawSpeedBonus[playerid]);
}