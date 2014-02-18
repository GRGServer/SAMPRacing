stock str_replace(search[], replace[], source[])
{
	new newnick[256];
	new newlen;
	for (new i; i < strlen(source); i++)
	{
		if (strlen(search) > 1 && i != (strlen(source) - 1))
		{
			new matched = 1;
			new start = i;
			for (new s=0; s < strlen(search) && matched == 1; s++)
			{
				if (source[i] != search[s] && s == 0)
				{
					newnick[newlen] = source[i];
					matched = 0;
				} else
				{
					if (source[i] == search[s])
					{
						i++;
					} else
					{
						matched = 0;
					}
				}
			}
			if (matched == 0)
			{
				while (start <= i)
				{
					newnick[newlen] = source[start];
					newlen++;
					start++;
				}
			}
			else
			{
				for (new r; r < strlen(replace); r++)
				{
					newnick[newlen] = replace[r];
					newlen++;
				}
				i = (start + (strlen(search) - 1));
			}
		}
		else
		{
			if (strlen(search) == 1 && source[i] == search[0])
			{
				for (new r; r < strlen(replace); r++)
				{
					newnick[newlen] = replace[r];
					newlen++;
				}
			}
			else
			{
				newnick[newlen] = source[i];
				newlen++;
			}
		}
	}
	newnick[newlen] = EOS;
	return newnick;
}