UpdateDrifting(playerID)
{
	// Drifting is enabled and player is the driver
	if (PVar:playerID[DRIFTING_STATE] && GetPlayerVehicleSeat(playerID) == 0)
	{
		new vehicleID = GetPlayerVehicleID(playerID);

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
				PVar:playerID[DRIFTING_SCORESTATE] = true;
				PVar:playerID[DRIFTING_SCORE]++;
				GivePlayerMoney(playerID, PVar:playerID[DRIFTING_SCORE] / 10);

				if ((25 < angle < 70) || (290 < angle < 335))
				{
					PVar:playerID[DRIFTING_SCORE]++;
					if ((35 < angle < 45) || (315 < angle < 325))
					{
						PVar:playerID[DRIFTING_SCORE]++;
						PVar:playerID[DRIFTING_ANGLEBONUS]++;
					}
				}

				if (speed > 0.6)
				{
					PVar:playerID[DRIFTING_SCORE]++;
					PVar:playerID[DRIFTING_SPEEDBONUS]++;
				}
			}
			// Player stops drifting
			else if (PVar:playerID[DRIFTING_SCORE])
			{
				if (PVar:playerID[DRIFTING_SCORESTATE])
				{
					if (PVar:playerID[DRIFTING_SCORE] > PVar:playerID[DRIFTING_MAXSCORE])
					{
						PVar:playerID[DRIFTING_MAXSCORE] = PVar:playerID[DRIFTING_SCORE];
						if (PVar:playerID[DRIFTING_SCORE] > PVar:playerID[DRIFTING_BESTSCORE])
						{
							PVar:playerID[DRIFTING_BESTSCORE] = PVar:playerID[DRIFTING_SCORE];
						}
					}
					else
					{
						if (PVar:playerID[DRIFTING_SCORE] > 70)
						{
							RepairVehicle(vehicleID);
							SetVehicleHealth(vehicleID, 1000);
							AddVehicleComponent(vehicleID, 1009);
						}
					}
					PVar:playerID[DRIFTING_LASTSCORE] = PVar:playerID[DRIFTING_SCORE];
					PVar:playerID[DRIFTING_SCORESTATE] = false;

					GivePlayerMoney(playerID, PVar:playerID[DRIFTING_ANGLEBONUS] / 10);
					GivePlayerMoney(playerID, PVar:playerID[DRIFTING_SPEEDBONUS] / 5);
					GivePlayerMoney(playerID, PVar:playerID[DRIFTING_SCORE] / 2);
				}

				// Reset values
				PVar:playerID[DRIFTING_SPEEDBONUS] = 0;
				PVar:playerID[DRIFTING_ANGLEBONUS] = 0;

				PVar:playerID[DRIFTING_SCORE]--;
			}
		}
		else if (PVar:playerID[DRIFTING_SCORE])
		{
			if (PVar:playerID[DRIFTING_SCORE] > PVar:playerID[DRIFTING_BESTSCORE])
			{
				PVar:playerID[DRIFTING_BESTSCORE] = PVar:playerID[DRIFTING_SCORE];
			}

			PVar:playerID[DRIFTING_LASTSCORE] = PVar:playerID[DRIFTING_SCORE];

			// Reset values
			PVar:playerID[DRIFTING_SCORE] = 0;
			PVar:playerID[DRIFTING_SPEEDBONUS] = 0;
			PVar:playerID[DRIFTING_ANGLEBONUS] = 0;
		}

		new string[100];

		Format:string(LanguageString(playerID, StringID:43("Drift Score: %d~n~~n~Best Score: %d * Last Score: %d")), PVar:playerID[DRIFTING_SCORE], PVar:playerID[DRIFTING_BESTSCORE], PVar:playerID[DRIFTING_LASTSCORE]);
		PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM], string);

		Format:string("%d~n~~n~%d", PVar:playerID[DRIFTING_SPEEDBONUS], PVar:playerID[DRIFTING_ANGLEBONUS]);
		PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES], string);

		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS]);
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES]);
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM]);
	}
	else
	{
		PVar:playerID[DRIFTING_ANGLEBONUS] = 0;
		PVar:playerID[DRIFTING_BESTSCORE] = 0;
		PVar:playerID[DRIFTING_LASTSCORE] = 0;
		PVar:playerID[DRIFTING_MAXSCORE] = 0;
		PVar:playerID[DRIFTING_SCORE] = 0;
		PVar:playerID[DRIFTING_SCORESTATE] = false;
		PVar:playerID[DRIFTING_SPEEDBONUS] = 0;

		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_LABELS]);
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BONUS_VALUES]);
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_DRIFTING_BOTTOM]);
	}
}