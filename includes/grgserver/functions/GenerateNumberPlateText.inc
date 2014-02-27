GenerateNumberPlateText(prefix[])
{
	new string[STRINGLENGTH_NUMBERPLATE];
	new try;

	do
	{
		// Generate a random string in format "<prefix><A-Z><A-Z><1-9999>"
		Format:string("%s%c%c%d", prefix, random(26) + 65, random(26) + 65, random(9999) + 1);

		if (CheckNumberPlate(string))
		{
			return string;
		}

		try++;
	}
	while (try < MAX_RANDOMNUMBERPLATE_TRIES);

	strdel(string, 0, strlen(string));

	return string;
}