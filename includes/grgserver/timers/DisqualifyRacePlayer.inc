Timer:DisqualifyRacePlayer(playerID)
{
	if (PVar:playerID[RACE_DISQUALIFY_TIMEOUT] <= 0)
	{
		DisqualifyRacePlayer(playerID);
	}
	else
	{
		FormatNew:string[100]("~r~%s~n~~n~%d", LanguageString(playerID, StringID:183("Get back to your vehicle!")), PVar:playerID[RACE_DISQUALIFY_TIMEOUT]);
		GameTextForPlayer(playerID, string, 2000, 3);
		PVar:playerID[RACE_DISQUALIFY_TIMEOUT]--;
	}
}