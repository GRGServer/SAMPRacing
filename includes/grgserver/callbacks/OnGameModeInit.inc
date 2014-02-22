public OnGameModeInit()
{
	SetGameModeText("Grand Racing Game");

	maxPlayers = GetServerVarAsInt("maxplayers");

	print("Connecting to MySQL server");
	mysql_init();
	mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);

	ReloadLanguageStrings();
	ReloadVehicleModels();
	ReloadTeleports();

	textDrawClock = TextDrawCreate(547, 25, "_");
	TextDrawSetShadow(textDrawClock, 0);
	TextDrawSetOutline(textDrawClock, 2);
	TextDrawLetterSize(textDrawClock, 0.6, 1.8);
	TextDrawFont(textDrawClock, 3);

	print("Starting timers");
	SetTimer("Timer_EverySecond", 1000, true);
}