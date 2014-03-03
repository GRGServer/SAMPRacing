Hash(string[], salt[] = "")
{
	new hashString[STRINGLENGTH_HASH];
	new saltString[STRINGLENGTH_HASH];

	if (StrNotNull(salt))
	{
		strcat(saltString, salt);
	}
	else
	{
		FormatNew:newSalt[10]("%d%d", gettime(), random(1000));
		WP_Hash(saltString, sizeof(saltString), newSalt);
	}

	FormatNew:saltedString[STRINGLENGTH_HASH + STRINGLENGTH_HASHSTRING + 2]("%s$%s", saltString, string);
	WP_Hash(hashString, sizeof(hashString), saltedString);

	FormatNew:buffer[STRINGLENGTH_HASH * 2 + 2]("%s$%s", saltString, hashString);
	return buffer;
}