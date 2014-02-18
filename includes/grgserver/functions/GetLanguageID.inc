/**
 * <summary>
 *	Get the ID of the specified language
 * </summary>
 *
 * <param name="name">
 *	The name of the language (e.g. "de" or "en")
 * </param>
 *
 * <returns>
 *	The ID of the language
 * </returns>
 */

GetLanguageID(name[])
{
	if (IsStr(name, "de"))
	{
		return LANGUAGE_GERMAN;
	}
	return LANGUAGE_ENGLISH;
}