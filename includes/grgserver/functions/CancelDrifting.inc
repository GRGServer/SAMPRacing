CancelDrifting(playerid)
{
	DriftingState[playerid] = false;
    ScoreState[playerid] = false;
	Score[playerid] = 0;
	SetPVarInt(playerid, "MaxScore", 0);
	SetPVarInt(playerid, "SpeedBonus", 0);
	SetPVarInt(playerid, "AngleBonus", 0);
	TextDrawHideForPlayer(playerid,DrawScore[playerid]);
	TextDrawHideForPlayer(playerid,DrawBestScore[playerid]);
	TextDrawHideForPlayer(playerid,DrawLastScore[playerid]);
	TextDrawHideForPlayer(playerid, DrawSpeedBonus[playerid]);
	TextDrawHideForPlayer(playerid, DrawAngleBonus[playerid]);
	return 1;
}
