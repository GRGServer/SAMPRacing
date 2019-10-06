public OnGameModeInit()
{
    SetGameModeText("Grand Racing Game");

    g_maxPlayers = GetServerVarAsInt("maxplayers");

    print("Connecting to MySQL server");
    g_mysql = mysql_connect_file();

    if (mysql_errno() == 0)
    {
        print("Successfully connected to MySQL server");
    }
    else
    {
        print("Can't connect to MySQL server!");
        return;
    }

    GetEnv("GRG_AUDIO_URL", g_audioUrl);
    printf("Using Audio URL: %s", g_audioUrl);

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

    g_textDrawClock = TextDrawCreate(547, 25, "_");
    TextDrawSetShadow(g_textDrawClock, 0);
    TextDrawSetOutline(g_textDrawClock, 2);
    TextDrawLetterSize(g_textDrawClock, 0.6, 1.8);
    TextDrawFont(g_textDrawClock, 3);

    print("Starting timers");
    SetTimer:EverySecond(1000, true);
    SetTimer:EveryMinute(60000, true);
    SetTimer:UpdateVehicleStats(100, true);
}