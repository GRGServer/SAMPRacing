public OnGameModeInit()
{
	print("Connecting to MySQL server");
	mysql_init();
	mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);

	SetGameModeText("Grand Racing Game");
}