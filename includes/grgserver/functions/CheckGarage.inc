CheckGarage(playerID)
{
	new foundGarage = false;
	Foreach(index, g_garages)
	{
		if (PVar:playerID[USERID] == g_garages[index][E_GARAGE_USERID] && IsPlayerInRangeOfPoint(playerID, g_garages[index][E_GARAGE_ENTERRANGE], g_garages[index][E_GARAGE_VEHICLE_POSX], g_garages[index][E_GARAGE_VEHICLE_POSY], g_garages[index][E_GARAGE_VEHICLE_POSZ]))
		{
			foundGarage = true;
			if (!PVar:playerID[GARAGE_ISINSIDE])
			{
				PVar:playerID[GARAGE_ISINSIDE] = true;
				EnterGarage(playerID, index);
			}
			break;
		}
	}

	if (!foundGarage && PVar:playerID[GARAGE_NUMBER] == -1)
	{
		PVar:playerID[GARAGE_ISINSIDE] = false;
	}
}