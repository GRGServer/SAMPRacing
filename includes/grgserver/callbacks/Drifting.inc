forward Drifting(playerID);
public Drifting(playerID)
{
	/*Speed calculation*/
	new Float:x, Float:y, Float:z, vid;
	vid = GetPlayerVehicleID(playerID);
	GetVehicleVelocity(vid, x, y, z);
	speed = floatpower(x*x+y*y, 0.5);
	if (speed > 0.2)
	{
		/*Trig functions for calculating moving(travelling) direction*/
		if (x<0)
		{
  			if(y>0)
  				{ TDirection = atan(floatabs(x/y)); }
			else if (y<=0)
				{ TDirection = atan(y/x) + 90; }
		}
		else if (x>0)
		{
  			if(y<0)
	    		{ TDirection = atan(floatabs(x/y)) + 180; }
			else if (y>=0)
				{ TDirection = atan(y/x) + 270; }
		}
		else if (x==0)
		{
			if (y>0)
				{ TDirection = 0; }
			else if (y<0)
				{ TDirection = 180; }
		}
		/*Calculations for drifting angle*/
		GetVehicleZAngle(vid, CDirection);
		DriftAngle = floatabs(TDirection - CDirection);
		/*Adding score*/
		if ((15 < DriftAngle < 80) || ( 280 < DriftAngle < 345)) //At least a 15 degree angle is required to score anything
		{
			ScoreState[playerID] = true;
			Score[playerID]++;
			if ((25 < DriftAngle < 70) || (290 < DriftAngle < 335)) //At least a 25 degree angle is required to score 2 points
			{
				Score[playerID]++;
				if ((35 < DriftAngle < 45) || (315 < DriftAngle < 325)) //35-45 degree drifts receive additional bonuses
				{
				    Score[playerID]++;
        			SetPVarInt(playerID, "AngleBonus", GetPVarInt(playerID, "AngleBonus")+1);
				    format(driftstring,sizeof(driftstring),"Winkel Bonus + %d !", GetPVarInt(playerID, "AngleBonus"));
				    TextDrawSetString(DrawAngleBonus[playerID], driftstring);
					TextDrawShowForPlayer(playerID, DrawAngleBonus[playerID]);
				}
			}
			if (speed > 0.6)
				{
				    Score[playerID]++;
        			SetPVarInt(playerID, "SpeedBonus", GetPVarInt(playerID, "SpeedBonus")+1);
				    format(driftstring,sizeof(driftstring),"Geschwindigkeits Bonus + %d !", GetPVarInt(playerID, "SpeedBonus"));
				    TextDrawSetString(DrawSpeedBonus[playerID], driftstring);
		    		TextDrawShowForPlayer(playerID, DrawSpeedBonus[playerID]);
				}
			format(driftstring, sizeof(driftstring), "Punkte: %d", Score[playerID]);
			TextDrawSetString(DrawScore[playerID], driftstring);
			}
		/*When the player stops drifting*/
		else if (Score[playerID]>0)
		{
  			if (ScoreState[playerID] == true)
			{
				if (Score[playerID] > GetPVarInt(playerID, "MaxScore"))
				{
					SetPVarInt(playerID, "MaxScore", Score[playerID]); 
					if (Score[playerID] > GetPVarInt(playerID, "AbsMaxScore"))
					{
						SetPVarInt(playerID, "AbsMaxScore", Score[playerID]);
						format(driftstring,sizeof(driftstring),"Beste: %d",GetPVarInt(playerID,"AbsMaxScore"));
						TextDrawSetString(DrawBestScore[playerID], driftstring); //Comment this line if you want to disable score updating(under TAB)
					}
					else
					{
						format(driftstring,sizeof(driftstring),"Letzte: %d",Score[playerID]);
						TextDrawSetString(DrawLastScore[playerID], driftstring);
					}
				}
				else
				{
					format(driftstring,sizeof(driftstring),"Letzte %d",Score[playerID]);
     				TextDrawSetString(DrawLastScore[playerID], driftstring);
					if (Score[playerID] > 70) //comment this bracket section if you don't want NOS/fixing with scoring (for example, when you have your own autofix)
					{
						RepairVehicle(vid);
						SetVehicleHealth(vid, 1000);
						AddVehicleComponent(vid, 1009); //2x nos
					}
				}
				ScoreState[playerID] = false;
			}
			TextDrawHideForPlayer(playerID, DrawSpeedBonus[playerID]);
			SetPVarInt(playerID, "SpeedBonus", 0);
			TextDrawHideForPlayer(playerID, DrawAngleBonus[playerID]);
			SetPVarInt(playerID, "AngleBonus", 0);
			Score[playerID]--;
			format(driftstring, sizeof(driftstring), "Punkte: %d", Score[playerID]);
			TextDrawSetString(DrawScore[playerID], driftstring);
		}
	}
	else if (Score[playerID] > 0)
	{
		if (Score[playerID] > GetPVarInt(playerID, "AbsMaxScore"))
		{
			SetPVarInt(playerID, "AbsMaxScore", Score[playerID]);
			format(driftstring,sizeof(driftstring),"Best drift: %d",Score[playerID]);
			TextDrawSetString(DrawBestScore[playerID], driftstring);
		}
		format(driftstring,sizeof(driftstring),"Letzte: %d",Score[playerID]);
		TextDrawSetString(DrawLastScore[playerID], driftstring);
		Score[playerID] = 0;
		TextDrawSetString(DrawScore[playerID], "Punkte: 0");
		TextDrawHideForPlayer(playerID, DrawSpeedBonus[playerID]);
		SetPVarInt(playerID, "SpeedBonus", 0);
		TextDrawHideForPlayer(playerID, DrawAngleBonus[playerID]);
		SetPVarInt(playerID, "AngleBonus", 0);
	}
}