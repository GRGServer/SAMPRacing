public OnGameModeExit()
{
	SavePlayers();

	mysql_close();
}