GetLanguageID(name[])
{
	if (IsStr(name, "de"))
	{
		return LANGUAGE_GERMAN;
	}

	return LANGUAGE_ENGLISH;
}