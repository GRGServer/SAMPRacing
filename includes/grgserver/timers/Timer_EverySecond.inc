Timer:EverySecond()
{
	new hour;
	new minute;
	gettime(hour, minute);

	FormatNew:clockString[6]("%02d:%02d", hour, minute);
	TextDrawSetString(textDrawClock, clockString);
}