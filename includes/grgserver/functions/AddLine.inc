AddLine(string[], line[], stringSize = sizeof(string))
{
	if (strlen(string))
	{
		strcat(string, "\n", stringSize);
	}
	strcat(string, line, stringSize);
}