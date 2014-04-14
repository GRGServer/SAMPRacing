CheckTuningGarage(playerID)
{
	new foundTuningGarage = false;

	if (GetPlayerVehicleSeat(playerID) == 0)
	{
		Foreach(index, g_tuningGarages)
		{
			if (g_tuningGarages[index][E_TUNINGGARAGE_ENTERRANGE] && IsPlayerInRangeOfPoint(playerID, g_tuningGarages[index][E_TUNINGGARAGE_ENTERRANGE], g_tuningGarages[index][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[index][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[index][E_TUNINGGARAGE_VEHICLE_POSZ]))
			{
				foundTuningGarage = true;
				if (!PVar:playerID[TUNINGGARAGE_ISINSIDE])
				{
					PVar:playerID[TUNINGGARAGE_ISINSIDE] = true;
					EnterTuningGarage(playerID, index);
				}
				break;
			}
		}
	}

	if (!foundTuningGarage && PVar:playerID[TUNINGGARAGE_NUMBER] == -1)
	{
		PVar:playerID[TUNINGGARAGE_ISINSIDE] = false;
	}
}