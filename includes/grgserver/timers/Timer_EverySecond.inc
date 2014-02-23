Timer:EverySecond()
{
	new hour;
	new minute;
	gettime(hour, minute);

	SetWorldTime(hour);

	FormatNew:clockString[6]("%02d:%02d", hour, minute);
	TextDrawSetString(g_textDrawClock, clockString);
}