UpdateVehicleStateForPlayer(playerID)
{
	new string[256];

	new vehicleID = GetPlayerVehicleID(playerID);

	// Speed calculcation
	new Float:velocityX;
	new Float:velocityY;
	new Float:velocityZ;
	GetVehicleVelocity(vehicleID, velocityX, velocityY, velocityZ);
	new speed = floatround(floatsqroot(floatpower(velocityX, 2) + floatpower(velocityY, 2) + floatpower(velocityZ, 2)) * 100 * 1.61);

	// Player is in a vehicle
	if (vehicleID)
	{
		new Float:health;
		GetVehicleHealth(vehicleID, health);

		// Fix infinite health
		if (health > 1000)
		{
			health = 1000;
		}

		// Update vehicle info
		Format:string("~n~~n~%d km/h~n~%.0f%%", speed, health / 10);
		PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES], string);
		PlayerTextDrawSetString(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME], g_vehicleModels[GetVehicleModel(vehicleID) - 400][E_VEHICLEMODEL_NAME]);

		// Show vehicle info
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS]);
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME]);
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES]);
	}
	else
	{
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_LABELS]);
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_NAME]);
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_VEHICLEINFO_VALUES]);
	}

	// Drifting is enabled and player is the driver
	if (PVar:playerID[DRIFTING_STATE] && GetPlayerVehicleSeat(playerID) == 0)
	{
		if (speed >= 30)
		{
			// Get direction
			new Float:direction;
			if (velocityX < 0)
			{
				if (velocityY > 0)
				{
					direction = atan(floatabs(velocityX / velocityY));
				}
				else if (velocityY <= 0)
				{
					direction = atan(velocityY / velocityX) + 90;
				}
			}
			else if (velocityX > 0)
			{
				if (velocityY < 0)
				{
					direction = atan(floatabs(velocityX / velocityY)) + 180;
				}
				else if (velocityY >= 0)
				{
					direction = atan(velocityY / velocityX) + 270;
				}
			}
			else if (velocityX == 0)
			{
				if (velocityY > 0)
				{ 
					direction = 0;
				}
				else if (velocityY < 0)
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

				if (speed > 100)
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