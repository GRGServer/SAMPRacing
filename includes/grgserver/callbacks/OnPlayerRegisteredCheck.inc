forward OnPlayerRegisteredCheck(playerID);
public OnPlayerRegisteredCheck(playerID)
{
    new rows;
    cache_get_row_count(rows);
    if (rows)
    {
        new language[10];
        cache_get_value(0, "language", language, 10);
        PVar:playerID[LANGUAGE] = GetLanguageID(language);

        // Show login dialog
        ShowDialog:Login(playerID);
    }
    else
    {
        // Show language selection of register process
        ShowDialog:Register_Language(playerID);
    }
}