forward OnPlayerGaragesLoaded(playerID);
public OnPlayerGaragesLoaded(playerID)
{
	Count(row, cache_get_row_count())
	{
		new garageID = cache_get_field_content_int(row, "id");
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