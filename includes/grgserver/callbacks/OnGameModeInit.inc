public OnGameModeInit()
{
    SetGameModeText("Grand Racing Game");

    g_maxPlayers = GetServerVarAsInt("maxplayers");

    print("Connecting to MySQL server");
    g_mysql = mysql_connect_file();

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
    ReloadTuningGarages();
    ReloadRaces();
    ReloadNPCs();

    LoadHiddenPackages();
    LoadCommands();

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