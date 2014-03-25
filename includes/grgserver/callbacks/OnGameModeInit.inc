public OnGameModeInit()
{
	SetGameModeText("Grand Racing Game");

	g_maxPlayers = GetServerVarAsInt("maxplayers");

	print("Connecting to MySQL server");
	mysql_log(MYSQL_LOGLEVEL);
	mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_DATABASE, MYSQL_PASSWORD);

	ReloadLanguageStrings();
	ReloadObjectModels();
	ReloadObjects();
	ReloadVehicleModels();
	ReloadVehicleShops();
	ReloadCommandAliases();
	ReloadInteriors();
	ReloadTeleports();
	ReloadAreas();
	ReloadPickups();
	ReloadVehicles();
	ReloadGarages();
	ReloadRaces();

	LoadHiddenPackages();
	LoadCommands();
	//LoadNPCs();
	
	ConnectNPC("LSTest1","LSTest1");
	ConnectNPC("LSTest2","LSTest2");
	ConnectNPC("LSTest3","LSTest3");
	g_car_LSTest1 = CreateVehicle(445, 2073.809814, -1819.895751, 13.279934, 88.126510 , 10, 1, -1);
	g_car_LSTest2 = CreateVehicle(401, 2074.655273, -1814.141235, 13.115847, 90.339157, 10, 1, -1);
	g_car_LSTest3 = CreateVehicle(496, 2073.659179, -1805.274658, 13.219514, 89.845085, 10, 1, -1);
	
	
	g_textDrawClock = TextDrawCreate(547, 25, "_");
	TextDrawSetShadow(g_textDrawClock, 0);
	TextDrawSetOutline(g_textDrawClock, 2);
	TextDrawLetterSize(g_textDrawClock, 0.6, 1.8);
	TextDrawFont(g_textDrawClock, 3);

	print("Starting timers");
	SetTimer("Timer_EverySecond", 1000, true);
	SetTimer("Timer_EveryMinute", 60000, true);
	SetTimer("Timer_UpdateVehicleStats", 100, true);
}