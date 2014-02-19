GetLanguageByID(language)
{
	new name[3];
	switch (language)
	{
		case LANGUAGE_GERMAN:
		{
			name = "de";
		}
		default:
		{
			name = "en";
		}
	}
	return name;
}