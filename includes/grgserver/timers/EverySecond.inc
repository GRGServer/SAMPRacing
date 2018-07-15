Timer:EverySecond()
{
    new hour;
    new minute;
    gettime(hour, minute);

    SetWorldTime(hour);

    FormatNew:clockString[6]("%02d:%02d", hour, minute);
    TextDrawSetString(g_textDrawClock, clockString);

    new playerStatsString[100];
    new Float:posX;
    new Float:posY;
    new Float:posZ;
    new vehicleModelID;
    new File:playerStatsFile = fopen("playerstats.dat", io_write);

    PlayerLoop(playerID)
    {
        SetPlayerTime(playerID, hour, minute);

        if (PVar:playerID[USERID])
        {
            // Write player info
            vehicleModelID = 0;
            if (IsPlayerInAnyVehicle(playerID))
            {
                vehicleModelID = GetVehicleModel(GetPlayerVehicleID(playerID));
            }
            GetPlayerPos(playerID, posX, posY, posZ);
            Format:playerStatsString("%d\t%s\t%f\t%f\t%f\t%d\t%d\n", playerID, GetPlayerNameEx(playerID), posX, posY, posZ, GetPlayerInterior(playerID), vehicleModelID);
            fwrite(playerStatsFile, playerStatsString);

            // Update current area
            new areaCount = GetPlayerNumberDynamicAreas(playerID);
            if (areaCount)
            {
                new areas[MAX_AREAS];
                GetPlayerDynamicAreas(playerID, areas);
                new areaID = Streamer_GetIntData(STREAMER_TYPE_AREA, areas[0], E_STREAMER_EXTRA_ID);
                if (PVar:playerID[CURRENT_AREA] != areaID + 1)
                {
                    // Exit the old area
                    if (PVar:playerID[CURRENT_AREA])
                    {
                        OnPlayerExitArea(playerID, PVar:playerID[CURRENT_AREA] - 1);
                    }

                    // Enter the area
                    PVar:playerID[CURRENT_AREA] = areaID + 1;
                    OnPlayerEnterArea(playerID, areaID);
                }
            }
            else
            {
                // Exit the area
                if (PVar:playerID[CURRENT_AREA])
                {
                    OnPlayerExitArea(playerID, PVar:playerID[CURRENT_AREA] - 1);
                    PVar:playerID[CURRENT_AREA] = 0;
                }
            }

            CheckGarage(playerID);

            CheckHiddenPackages(playerID);
        }
    }

    fclose(playerStatsFile);
}