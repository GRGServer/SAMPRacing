LanguageString(playerID, stringID)
{
	new string[STRINGLENGTH_LANGUAGESTRING];
	if (playerID == INVALID_PLAYER_ID)
	{
		strcat(string, languageStrings[stringID][LANGUAGESTRING_ENGLISH]);
	}
	else
	{
		switch (PVar:playerID[LANGUAGE])
		{
			case LANGUAGE_GERMAN:
			{
				strcat(string, languageStrings[stringID][LANGUAGESTRING_GERMAN]);
			}
			default:
			{
				strcat(string, languageStrings[stringID][LANGUAGESTRING_ENGLISH]);
			}
		}
	}
	return string;
}