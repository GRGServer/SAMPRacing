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
	
	  
    SetTimer("Timer_SpeedoMeterUp", UpdateConfig, true);
    
    for(new v=0; v<MAX_VEHICLES; v++)
	{
		ReadPosition(v);
	}
	for(new i=0; i<PLAYERS; i++)
	{
		#if TextBox
		LBox[i] = TextDrawCreate(612.000000,338.000000,"C");
		TextDrawUseBox(LBox[i],1);
		TextDrawBoxColor(LBox[i],0x00000033);
		TextDrawTextSize(LBox[i],454.000000,9.000000);
		TextDrawAlignment(LBox[i],0);
		TextDrawBackgroundColor(LBox[i],0x000000ff);
		TextDrawFont(LBox[i],3);
		TextDrawLetterSize(LBox[i],-0.000000,8.700001);
		TextDrawColor(LBox[i],BoxColor);
		TextDrawSetOutline(LBox[i],1);
		TextDrawSetProportional(LBox[i],1);
		TextDrawSetShadow(LBox[i],1);
		#endif


		#if TextTopLines
		LLine1[i] = TextDrawCreate(609.000000,341.000000,"L");
		TextDrawUseBox(LLine1[i],1);
		TextDrawBoxColor(LLine1[i],0xffffff33);
		TextDrawTextSize(LLine1[i],457.000000,-1.000000);
		TextDrawAlignment(LLine1[i],0);
		TextDrawBackgroundColor(LLine1[i],0x000000ff);
		TextDrawFont(LLine1[i],3);
		TextDrawLetterSize(LLine1[i],-0.000000,-0.400000);
		TextDrawColor(LLine1[i],TopLinesColor);
		TextDrawSetOutline(LLine1[i],1);
		TextDrawSetProportional(LLine1[i],1);
		TextDrawSetShadow(LLine1[i],1);
		
		LLine2[i] = TextDrawCreate(609.000000,416.000000,"L");
		TextDrawUseBox(LLine2[i],1);
		TextDrawBoxColor(LLine2[i],0xffffff33);
		TextDrawTextSize(LLine2[i],457.000000,-9.000000);
		TextDrawBackgroundColor(LLine2[i],0x000000ff);
		TextDrawFont(LLine2[i],3);
		TextDrawLetterSize(LLine2[i],-0.000000,-0.400000);
		TextDrawColor(LLine2[i],TopLinesColor);
		TextDrawSetOutline(LLine2[i],1);
		TextDrawSetProportional(LLine2[i],1);
		TextDrawSetShadow(LLine2[i],1);
		#endif

		#if LogoName
		LCredits[i] = TextDrawCreate(487.000000,320.000000,SpeedoLogoText);
		TextDrawAlignment(LCredits[i],0);
		TextDrawBackgroundColor(LCredits[i],0x000000ff);
		TextDrawFont(LCredits[i],0);
		TextDrawLetterSize(LCredits[i],0.399999,1.400000);
		TextDrawColor(LCredits[i],LogoColor);
		TextDrawSetOutline(LCredits[i],1);
		TextDrawSetProportional(LCredits[i],1);
		TextDrawSetShadow(LCredits[i],1);
		#endif


		#if TextSideLines
		LLine3[i] = TextDrawCreate(466.000000,343.000000,"T");
		TextDrawUseBox(LLine3[i],1);
		TextDrawBoxColor(LLine3[i],0xffffff33);
		TextDrawTextSize(LLine3[i],457.000000,0.000000);
		TextDrawAlignment(LLine3[i],0);
		TextDrawBackgroundColor(LLine3[i],0x000000ff);
		TextDrawFont(LLine3[i],3);
		TextDrawLetterSize(LLine3[i],-0.000000,7.499998);
		TextDrawColor(LLine3[i],SideLinesColor);
		TextDrawSetOutline(LLine3[i],1);
		TextDrawSetProportional(LLine3[i],1);
		TextDrawSetShadow(LLine3[i],1);
		

		LLine4[i] = TextDrawCreate(607.000000,343.000000,"T");
		TextDrawUseBox(LLine4[i],1);
		TextDrawBoxColor(LLine4[i],0xffffff33);
		TextDrawTextSize(LLine4[i],603.000000,-6.000000);
		TextDrawAlignment(LLine4[i],0);
		TextDrawBackgroundColor(LLine4[i],0x000000ff);
		TextDrawFont(LLine4[i],3);
		TextDrawLetterSize(LLine4[i],-0.000000,7.499999);
		TextDrawColor(LLine4[i],SideLinesColor);
		TextDrawSetOutline(LLine4[i],1);
		TextDrawSetProportional(LLine4[i],1);
		TextDrawSetShadow(LLine4[i],1);
		#endif
		

		format(lstring, sizeof(lstring), "Inicializing...");
		LFunc[i] = TextDrawCreate(466.000000,343.000000,lstring);
		TextDrawAlignment(LFunc[i],0);
		TextDrawBackgroundColor(LFunc[i],0x000000ff);
		TextDrawFont(LFunc[i],1);
		TextDrawLetterSize(LFunc[i],0.299999,1.200000);
		TextDrawColor(LFunc[i],0xffffffff);
		TextDrawSetOutline(LFunc[i],1);
		TextDrawSetProportional(LFunc[i],1);
		TextDrawSetShadow(LFunc[i],1);
		

		format(lstr, sizeof(lstr), "Inicializing...");
		Lmph[i] = TextDrawCreate(466.000000,400.000000,lstr);
		TextDrawAlignment(Lmph[i],0);
		TextDrawBackgroundColor(Lmph[i],0x000000ff);
		TextDrawFont(Lmph[i],1);
		TextDrawLetterSize(Lmph[i],0.299999,1.000000);
		TextDrawColor(Lmph[i],0xffffffff);
		TextDrawSetOutline(Lmph[i],1);
		TextDrawSetProportional(Lmph[i],1);
		TextDrawSetShadow(Lmph[i],1);
	}
}