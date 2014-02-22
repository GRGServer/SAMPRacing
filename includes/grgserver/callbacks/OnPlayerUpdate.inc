public OnPlayerUpdate(playerid)
{
	new vehicleID = GetPlayerVehicleID(playerid);
	new vehicleSeat = GetPlayerVehicleSeat(playerid);

	if (PVar:playerid[GODMODE])
	{
		SetPlayerHealth(playerid, 999999999);

		if (vehicleSeat == 0)
		{
			SetVehicleHealth(vehicleID, 999999999);
		}
	}

	// Drifting is enabled and player is the driver
	if (PVar:playerid[DRIFTING_STATE] && vehicleSeat == 0)
	{
		new driftString[100];

		// Speed calculcation
		new Float:x;
		new Float:y;
		new Float:z;
		GetVehicleVelocity(vehicleID, x, y, z);
		new Float:speed = floatpower(x * x + y * y, 0.5);

		if (speed > 0.2)
		{
			// Get direction
			new Float:direction;
			if (x < 0)
			{
				if(y > 0)
				{ 
					direction = atan(floatabs(x/y)); 
				}
				else if (y <= 0)
				{ 
					direction = atan(y/x) + 90; 
				}
			}
			else if (x > 0)
			{
				if(y < 0)
				{
					direction = atan(floatabs(x/y)) + 180; 
				}
				else if (y >= 0)
				{
					direction = atan(y/x) + 270; 
				}
			}
			else if (x == 0)
			{
				if (y > 0)
				{ 
					direction = 0; 
				}
				else if (y < 0)
				{ 
					direction = 180; 
				}
			}

			// Calculate drifting angle
			new Float:currentDirection;
			GetVehicleZAngle(vehicleID, currentDirection);
			new Float:angle = floatabs(direction - currentDirection);

			// Calculate score
			if ((15 < angle < 80) || ( 280 < angle < 345))
			{
				PVar:playerid[DRIFTING_SCORESTATE] = true;
				PVar:playerid[DRIFTING_SCORE]++;

				if ((25 < angle < 70) || (290 < angle < 335))
				{
					PVar:playerid[DRIFTING_SCORE]++;
					if ((35 < angle < 45) || (315 < angle < 325))
					{
						PVar:playerid[DRIFTING_SCORE]++;
						PVar:playerid[DRIFTING_ANGLEBONUS]++;
						Format:driftString(LanguageString(playerid, StringID:44("Angle bonus + %d")), PVar:playerid[DRIFTING_ANGLEBONUS]++);
						PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_ANGLEBONUS], driftString);
						PlayerTextDrawShow(playerid, PTextDraw:playerid[DRIFTING_ANGLEBONUS]);
						GivePlayerMoney(playerid, PVar:playerid[DRIFTING_ANGLEBONUS]);
					}
				}

				if (speed > 0.6)
				{
					PVar:playerid[DRIFTING_SCORE]++;
					PVar:playerid[DRIFTING_SPEEDBONUS]++;
					Format:driftString(LanguageString(playerid, StringID:43("Speed bonus + %d")), PVar:playerid[DRIFTING_SPEEDBONUS]);
					PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_SPEEDBONUS], driftString);
					PlayerTextDrawShow(playerid, PTextDraw:playerid[DRIFTING_SPEEDBONUS]);
					GivePlayerMoney(playerid, PVar:playerid[DRIFTING_SPEEDBONUS]);
				}

				Format:driftString(LanguageString(playerid, StringID:47("Score: %d")), PVar:playerid[DRIFTING_SCORE]);
				PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_SCORE], driftString);
			}
			// Player stops drifting
			else if (PVar:playerid[DRIFTING_SCORE])
			{
				if (PVar:playerid[DRIFTING_SCORESTATE])
				{
					if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_MAXSCORE])
					{
						PVar:playerid[DRIFTING_MAXSCORE] = PVar:playerid[DRIFTING_SCORE];
						if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_ABSMAXSCORE])
						{
							PVar:playerid[DRIFTING_ABSMAXSCORE] = PVar:playerid[DRIFTING_SCORE];
							Format:driftString(LanguageString(playerid, StringID:49("Best: %d")), PVar:playerid[DRIFTING_ABSMAXSCORE]);
							PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_BESTSCORE], driftString); 
						}
						else
						{
							Format:driftString(LanguageString(playerid, StringID:48("Last: %d")), PVar:playerid[DRIFTING_SCORE]);
							PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_LASTSCORE], driftString);
						}
					}
					else
					{
						Format:driftString(LanguageString(playerid, StringID:48("Last: %d")), PVar:playerid[DRIFTING_SCORE]);
						PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_LASTSCORE], driftString);
						if (PVar:playerid[DRIFTING_SCORE] > 70)
						{
							RepairVehicle(vehicleID);
							SetVehicleHealth(vehicleID, 1000);
							AddVehicleComponent(vehicleID, 1009);
						}
					}
					PVar:playerid[DRIFTING_SCORESTATE] = false;
				}

				// Reset values
				PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_SPEEDBONUS]);
				PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
				PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_ANGLEBONUS]);
				PVar:playerid[DRIFTING_ANGLEBONUS] = 0;

				PVar:playerid[DRIFTING_SCORE]--;
				Format:driftString(LanguageString(playerid, StringID:47("Score: %d")), PVar:playerid[DRIFTING_SCORE]);
				PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_SCORE], driftString);
			}
		}
		else if (PVar:playerid[DRIFTING_SCORE])
		{
			if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_ABSMAXSCORE])
			{
				PVar:playerid[DRIFTING_ABSMAXSCORE] = PVar:playerid[DRIFTING_SCORE];
				Format:driftString(LanguageString(playerid, StringID:49("Best: %d")), PVar:playerid[DRIFTING_ABSMAXSCORE]);
				PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_BESTSCORE], driftString); 
			}

			Format:driftString(LanguageString(playerid, StringID:48("Last: %d")), PVar:playerid[DRIFTING_SCORE]);
			PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_LASTSCORE], driftString);

			PVar:playerid[DRIFTING_SCORE] = 0;
			Format:driftString(LanguageString(playerid, StringID:47("Score: %d")), PVar:playerid[DRIFTING_SCORE]);
			PlayerTextDrawSetString(playerid, PTextDraw:playerid[DRIFTING_SCORE], driftString);

			// Reset values
			PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_SPEEDBONUS]);
			PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
			PlayerTextDrawHide(playerid, PTextDraw:playerid[DRIFTING_ANGLEBONUS]);
			PVar:playerid[DRIFTING_ANGLEBONUS] = 0;
		}
	}
}