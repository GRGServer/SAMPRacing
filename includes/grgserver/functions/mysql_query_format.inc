Cache:mysql_query_format(bool:useCache, query[], {Float,_}:...)
{
	new formattedQuery[1024];
	new length = strlen(query);
	new argumentIndex = 1;

	for (new character = 0; character < length; character++)
	{
		new isFormatChar;
		if (query[character] == '%')
		{
			if (character + 1 < length)
			{
				switch (query[character + 1])
				{
					case '%':
					{
						strcat(formattedQuery, "%");
						isFormatChar = true;
					}
					case 'c':
					{
						argumentIndex++;
						Format:formattedQuery("%s%c", formattedQuery, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'd':
					{
						argumentIndex++;
						Format:formattedQuery("%s%d", formattedQuery, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'e':
					{
						argumentIndex++;
						new string[256];
						new escapedString[256];
						GetStringArg(argumentIndex, string);
						mysql_escape_string(string, escapedString);
						strcat(formattedQuery, escapedString);
						isFormatChar = true;
					}
					case 'f':
					{
						argumentIndex++;
						Format:formattedQuery("%s%f", formattedQuery, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 's':
					{
						argumentIndex++;
						new string[256];
						GetStringArg(argumentIndex, string);
						strcat(formattedQuery, string);
						isFormatChar = true;
					}
				}
			}
		}

		if (isFormatChar)
		{
			character++;
		}
		else
		{
			Format:formattedQuery("%s%c", formattedQuery, query[character]);
		}
	}

	return mysql_query(1, formattedQuery, useCache);
}