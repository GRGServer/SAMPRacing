Timer:SpeedoMeterUp()
{
    new Float:LPosX;
	new Float:LPosY;
	new Float:LPosZ;
	new Float:PlayerSpeedDistance;
	new value;
	new Float:L_VehHealth;
	new LVehicleStatus[15];
	
	for(new i=0; i<PLAYERS; i++)
	{
		if(VehicleStatus[GetPlayerVehicleID(i)] == 1)
		{
			LVehicleStatus = "~r~Locked";
		}
		else
		{
			LVehicleStatus = "~g~Unlocked";
		}
		if(IsPlayerConnected(i) && IsPlayerInAnyVehicle(i))
		{
			GetPlayerPos(i, LPosX, LPosY, LPosZ);
			GetPlayerVehicleID(i);
			GetVehicleHealth(GetPlayerVehicleID(i), L_VehHealth);
			PlayerSpeedDistance = floatsqroot(floatpower(floatabs(floatsub(LPosX,ReadPlayerPosition[i][ReadX])),2)+floatpower(floatabs(floatsub(LPosY,ReadPlayerPosition[i][ReadY])),2)+floatpower(floatabs(floatsub(LPosZ,ReadPlayerPosition[i][ReadZ])),2));
			value = floatround(PlayerSpeedDistance * 5000);
			new Zone[MAX_ZONE_NAME];
			if(SpeedoMeter[i] == 0)
			{
				TextDrawShowForPlayer(i, LBox[i]);
				TextDrawShowForPlayer(i, LLine1[i]);
				TextDrawShowForPlayer(i, LLine2[i]);
				TextDrawShowForPlayer(i, LLine3[i]);
				TextDrawShowForPlayer(i, LLine4[i]);
				TextDrawShowForPlayer(i, LCredits[i]);
				TextDrawShowForPlayer(i, Lmph[i]);
				TextDrawShowForPlayer(i, LFunc[i]);
				SpeedoMeter[i] = 1;	
			}
			new LMPH = floatround(value/1600);
			new LKPH = floatround(value/1000);
			
			Format:lstring("~b~Health: ~w~%.2f~n~~b~Altitude: ~w~%.1f~n~~b~Gps: ~w~%s~n~~b~Status: %s", L_VehHealth, LPosZ, Zone, LVehicleStatus);
			TextDrawSetString(LFunc[i], lstring);
			
			Format:lstr("%sMPH: ~w~%d  %sKM/H: ~w~%d",MPH_KPH_Color,LMPH,MPH_KPH_Color,LKPH);
			TextDrawSetString(Lmph[i], lstr);
			
			if(L_VehHealth <= 500)
			{
				Format:lstring("%s%sHealth: ~w~~r~%.2f~n~%sAltitude: ~w~%.1f~n~%sGps: ~w~%s",CategoriesColor, CategoriesColor, L_VehHealth, CategoriesColor, LPosZ,CategoriesColor,Zone);
				TextDrawSetString(LFunc[i], lstring);
			}
			if(LKPH >= VehicleMaxSpeed)
			{
				TogglePlayerControllable(i,0);
				LUnFreeze = SetTimer("_UnFreezeCar", 250, 1);
				Format:lstr("~g~MPH: ~w~%d  ~g~KM/H: ~r~%d",LMPH,LKPH);
				TextDrawSetString(Lmph[i], lstr);
			}
		}
		ReadPlayerPosition[i][ReadX] = LPosX, ReadPlayerPosition[i][ReadY] = LPosY, ReadPlayerPosition[i][ReadZ] = LPosZ;
	}
	for(new i=0; i<PLAYERS; i++)
	{
		if(!IsPlayerInAnyVehicle(i))
		{
			TextDrawHideForPlayer(i, LBox[i]);
			TextDrawHideForPlayer(i, LLine1[i]);
			TextDrawHideForPlayer(i, LLine2[i]);
			TextDrawHideForPlayer(i, LLine3[i]);
			TextDrawHideForPlayer(i, LLine4[i]);
			TextDrawHideForPlayer(i, LCredits[i]);
			TextDrawHideForPlayer(i, Lmph[i]);
			TextDrawHideForPlayer(i, LFunc[i]);
			SpeedoMeter[i] = 0;
		}
	}
	return true;
}