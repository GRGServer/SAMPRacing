forward OnPlayerRegisteredCheck(playerID);
public OnPlayerRegisteredCheck(playerID)
{
	if (cache_get_row_count())
	{
		PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));

		// Show login dialog
		ShowDialog:Login(playerID);
	}
	else
	{
		// Show language selection of register process
		ShowDialog:Register_Language(playerID);
	}
}