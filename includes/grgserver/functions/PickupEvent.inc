PickupEvent(playerID, pickupID, eventType)
{
    new linkID = g_pickups[pickupID][E_PICKUP_LINKID];

    switch (g_pickups[pickupID][E_PICKUP_TYPE])
    {
        case PICKUPTYPE_GARAGE_BOUGHT:
        {
            // TODO
        }
        case PICKUPTYPE_GARAGE_FREE:
        {
            switch (eventType)
            {
                case PICKUPEVENT_KEY:
                {
                    if (GetPlayerMoney(playerID) < g_garages[linkID][E_GARAGE_PRICE])
                    {
                        GameTextForPlayer(playerID, LanguageString(playerID, StringID:80("You do not have enough money!")), 3000, 3);
                    }
                    else
                    {
                        ShowDialog:ConfirmGarageBuy(playerID);
                    }
                }
                case PICKUPEVENT_PICKUP:
                {
                    SendClientMessageEx(playerID, COLOR_INFO, StringID:134("Press %s to use this pickup"), GetGameTextKeyByID(KEY_PICKUP_USE, false));
                }
            }
        }
        case PICKUPTYPE_HOSPITAL:
        {
            SetPlayerHealth(playerID, 100);
        }
        case PICKUPTYPE_RACE:
        {
            switch (eventType)
            {
                case PICKUPEVENT_KEY:
                {
                    if (g_races[linkID][E_RACE_STARTED])
                    {
                        GameTextForPlayer(playerID, LanguageString(playerID, StringID:156("This race has been already started!")), 3000, 3);
                    }
                    else
                    {
                        switch (GetPlayerVehicleSeat(playerID))
                        {
                            case -1:// Not in a vehicle
                            {
                                GameTextForPlayer(playerID, LanguageString(playerID, StringID:14("You are not in a vehicle!")), 3000, 3);
                            }
                            case 0:// Is the driver of the vehicle
                            {
                                if (GetPlayerScore(playerID) >= g_races[linkID][E_RACE_LEVEL])
                                {
                                    PVar:playerID[RACE_ID] = linkID;
                                    PVar:playerID[ALLOWCMDS] = false;
                                    PVar:playerID[RACE_LAP] = 1;
                                    PVar:playerID[RACE_VEHICLEID] = GetPlayerVehicleID(playerID);
                                    TogglePlayerControllable(playerID, false);
                                    FadeOutScreen(playerID, 5, 0, 0, 0, SCREENFADER_RACE_ENTERLOBBY);
                                }
                                else
                                {
                                    GameTextForPlayer(playerID, LanguageString(playerID, StringID:179("You do not have the required level!")), 3000, 3);
                                }
                            }
                            default:// Any other seat (Not the driver)
                            {
                                GameTextForPlayer(playerID, LanguageString(playerID, StringID:19("You are not the driver of this vehicle!")), 3000, 3);
                            }
                        }
                    }
                }
                case PICKUPEVENT_PICKUP:
                {
                    SendClientMessageEx(playerID, COLOR_INFO, StringID:134("Press %s to use this pickup"), GetGameTextKeyByID(KEY_PICKUP_USE, false));
                }
            }
        }
        case PICKUPTYPE_VEHICLESHOP:
        {
            EnterVehicleShop(playerID, linkID, false);
        }
    }

    PlaySound(playerID, SOUND_PICKUPEVENT);
    return true;
}