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
				GivePlayerMoney(playerid, PVar:playerid[DRIFTING_SCORE] / 10);

				if ((25 < angle < 70) || (290 < angle < 335))
				{
					PVar:playerid[DRIFTING_SCORE]++;
					if ((35 < angle < 45) || (315 < angle < 325))
					{
						PVar:playerid[DRIFTING_SCORE]++;
						PVar:playerid[DRIFTING_ANGLEBONUS]++;
					}
				}

				if (speed > 0.6)
				{
					PVar:playerid[DRIFTING_SCORE]++;
					PVar:playerid[DRIFTING_SPEEDBONUS]++;
				}
			}
			// Player stops drifting
			else if (PVar:playerid[DRIFTING_SCORE])
			{
				if (PVar:playerid[DRIFTING_SCORESTATE])
				{
					if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_MAXSCORE])
					{
						PVar:playerid[DRIFTING_MAXSCORE] = PVar:playerid[DRIFTING_SCORE];
						if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_BESTSCORE])
						{
							PVar:playerid[DRIFTING_BESTSCORE] = PVar:playerid[DRIFTING_SCORE];
						}
					}
					else
					{
						if (PVar:playerid[DRIFTING_SCORE] > 70)
						{
							RepairVehicle(vehicleID);
							SetVehicleHealth(vehicleID, 1000);
							AddVehicleComponent(vehicleID, 1009);
						}
					}
					PVar:playerid[DRIFTING_LASTSCORE] = PVar:playerid[DRIFTING_SCORE];
					PVar:playerid[DRIFTING_SCORESTATE] = false;

					GivePlayerMoney(playerid, PVar:playerid[DRIFTING_ANGLEBONUS] / 10);
					GivePlayerMoney(playerid, PVar:playerid[DRIFTING_SPEEDBONUS] / 5);
					GivePlayerMoney(playerid, PVar:playerid[DRIFTING_SCORE] / 2);
				}

				// Reset values
				PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
				PVar:playerid[DRIFTING_ANGLEBONUS] = 0;

				PVar:playerid[DRIFTING_SCORE]--;
			}
		}
		else if (PVar:playerid[DRIFTING_SCORE])
		{
			if (PVar:playerid[DRIFTING_SCORE] > PVar:playerid[DRIFTING_BESTSCORE])
			{
				PVar:playerid[DRIFTING_BESTSCORE] = PVar:playerid[DRIFTING_SCORE];
			}

			PVar:playerid[DRIFTING_LASTSCORE] = PVar:playerid[DRIFTING_SCORE];

			// Reset values
			PVar:playerid[DRIFTING_SCORE] = 0;
			PVar:playerid[DRIFTING_SPEEDBONUS] = 0;
			PVar:playerid[DRIFTING_ANGLEBONUS] = 0;
		}

		new string[100];

		Format:string(LanguageString(playerid, StringID:43("Drift Score: %d~n~~n~Best Score: %d * Last Score: %d")), PVar:playerid[DRIFTING_SCORE], PVar:playerid[DRIFTING_BESTSCORE], PVar:playerid[DRIFTING_LASTSCORE]);
		PlayerTextDrawSetString(playerid, g_playerTextDraws[playerid][E_PTD_DRIFTING_BOTTOM], string);

		Format:string("%d~n~~n~%d", PVar:playerid[DRIFTING_SPEEDBONUS], PVar:playerid[DRIFTING_ANGLEBONUS]);
		PlayerTextDrawSetString(playerid, g_playerTextDraws[playerid][E_PTD_DRIFTING_BONUS_VALUES], string);
	}
}