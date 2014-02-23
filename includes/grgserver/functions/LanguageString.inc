LanguageString(playerID, stringID)
{
	new string[STRINGLENGTH_LANGUAGESTRING];
	if (playerID == INVALID_PLAYER_ID)
	{
		strcat(string, g_languageStrings[stringID][E_LANGUAGESTRING_ENGLISH]);
	}
	else
	{
		switch (PVar:playerID[LANGUAGE])
		{
			case LANGUAGE_GERMAN:
			{
				strcat(string, g_languageStrings[stringID][E_LANGUAGESTRING_GERMAN]);
			}
			default:
			{
				strcat(string, g_languageStrings[stringID][E_LANGUAGESTRING_ENGLISH]);
			}
		}
	}
	return string;
}