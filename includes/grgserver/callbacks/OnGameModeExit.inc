public OnGameModeExit()
{
	SaveAll();

	mysql_close();
}