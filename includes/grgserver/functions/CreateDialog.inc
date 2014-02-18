CreateDialog(playerID, name[], style, title[], content[], button1[], button2[])
{
	SetPVarStr:playerID[CURRENTDIALOG][STRINGLENGTH_DIALOGNAME](name);
	ShowPlayerDialog(playerID, 0, style, title, content, button1, button2);
}