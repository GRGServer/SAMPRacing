UpdateMapIcons(playerID)
{
    Count(iconIndex, MAX_PLAYER_MAPICONS)
    {
        if (IsValidDynamicMapIcon(PVar:playerID[MAPICONS][iconIndex]))
        {
            DestroyDynamicMapIcon(PVar:playerID[MAPICONS][iconIndex]);
        }

        PVar:playerID[MAPICONS][iconIndex] = 0;
    }

    new iconIndex;

    Foreach(garageID, g_garages)
    {
        if (PVar:playerID[ISADMIN] || PVar:playerID[USERID] == g_garages[garageID][E_GARAGE_USERID])
        {
            if (iconIndex >= MAX_PLAYER_MAPICONS)
            {
                printf("Reached limit of %d player map icons", MAX_PLAYER_MAPICONS);
                return;
            }

            PVar:playerID[MAPICONS][iconIndex] = CreateDynamicMapIcon(g_garages[garageID][E_GARAGE_PICKUP_POSX], g_garages[garageID][E_GARAGE_PICKUP_POSY], g_garages[garageID][E_GARAGE_PICKUP_POSZ], MAPICONTYPE_GARAGE, 0, 0, 0, playerID, 6000, MAPICON_GLOBAL);
            iconIndex++;
        }
    }

    Foreach(raceID, g_races)
    {
        if (PVar:playerID[ISADMIN] || GetPlayerScore(playerID) == g_races[raceID][E_RACE_LEVEL])
        {
            if (iconIndex >= MAX_PLAYER_MAPICONS)
            {
                printf("Reached limit of %d player map icons", MAX_PLAYER_MAPICONS);
                return;
            }

            PVar:playerID[MAPICONS][iconIndex] = CreateDynamicMapIcon(g_races[raceID][E_RACE_PICKUP_POSX], g_races[raceID][E_RACE_PICKUP_POSY], g_races[raceID][E_RACE_PICKUP_POSZ], MAPICONTYPE_RACE, 0, 0, 0, playerID, 6000, MAPICON_GLOBAL);
            iconIndex++;
        }
    }
}