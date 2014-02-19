public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	if (DriftingState[playerid] == true)
	{
	    new a,b,c,d;
		GetVehicleDamageStatus(vehicleid, a,b,c,d);
		if (a || b || c || d == 1)
		{
			Score[playerid] = 0;
			TextDrawHideForPlayer(playerid, DrawSpeedBonus[playerid]);
			SetPVarInt(playerid, "SpeedBonus", 0);
			TextDrawHideForPlayer(playerid, DrawAngleBonus[playerid]);
			SetPVarInt(playerid, "AngleBonus", 0);
			TextDrawSetString(DrawScore[playerid], "This drift: 0");
		}
	}
	return 1;
}