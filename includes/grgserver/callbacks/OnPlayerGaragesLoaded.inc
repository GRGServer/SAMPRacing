forward OnPlayerGaragesLoaded(playerID);
public OnPlayerGaragesLoaded(playerID)
{
	new rows;
	cache_get_row_count(rows);
	Count(row, rows)
	{
		new garageID;
		cache_get_value_int(row, "id", garageID);
		Foreach(garageNumber, g_garages)
		{
			if (g_garages[garageNumber][E_GARAGE_ID] == garageID)
			{
				g_garages[garageNumber][E_GARAGE_USERID] = PVar:playerID[USERID];

				UpdateGarage(garageNumber);
				break;
			}
		}
	}
}