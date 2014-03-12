forward OnGarageVehicleCountLoaded(playerID, garageNumber);
public OnGarageVehicleCountLoaded(playerID, garageNumber)
{
	if (cache_get_row_count())
	{
		EnterGarage(playerID, garageNumber);
	}
	else
	{
		GameTextForPlayer(playerID, LanguageString(playerID, StringID:146("There are no vehicles in this garage!")), 3000, 3);
	}
}