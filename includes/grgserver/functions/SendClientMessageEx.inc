SendClientMessageEx(playerID, color, languageStringID, { _, Float, Text3D, Menu, Text, DB, DBResult, bool, File, hex, bit, bit_byte, Bit }:...)
{
	if (playerID == INVALID_PLAYER_ID)
	{
		return;
	}
	new targetString[256];
	new message[256];
	strcat(message, LanguageString(playerID, languageStringID));
	new length = strlen(message);
	new argumentIndex = 2;
	for (new character = 0; character < length; character++)
	{
		new isFormatChar;
		if (message[character] == '%')
		{
			if (character + 1 < length)
			{
				switch (message[character + 1])
				{
					case '%':
					{
						strcat(targetString, "%");
						isFormatChar = true;
					}
					case 'c':
					{
						argumentIndex++;
						Format:targetString("%s%c", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'd':
					{
						argumentIndex++;
						Format:targetString("%s%d", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'f':
					{
						argumentIndex++;
						Format:targetString("%s%f", targetString, getarg(argumentIndex));
						isFormatChar = true;
					}
					case 'l':
					{
						argumentIndex++;
						strcat(targetString, LanguageString(playerID, getarg(argumentIndex)));
						isFormatChar = true;
					}
					case 'm':
					{
						argumentIndex++;
						Format:targetString("%s$%s", targetString, FormatMoney(getarg(argumentIndex)));
						isFormatChar = true;
					}
					case 'p':
					{
						argumentIndex++;
						strcat(targetString, GetPlayerNameEx(getarg(argumentIndex)));
						isFormatChar = true;
					}
					case 's':
					{
						argumentIndex++;
						new string[256];
						GetStringArg(argumentIndex, string);
						strcat(targetString, string);
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
			Format:targetString("%s%c", targetString, message[character]);
		}
	}
	SendClientMessage(playerID, color, targetString);
}