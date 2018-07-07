PCMD:jetpack[ISADMIN](playerID, params[], StringID:67("Get a Jetpack"))
{
    SetPlayerSpecialAction(playerID, SPECIAL_ACTION_USEJETPACK);
    SendClientMessageEx(playerID, COLOR_INFO, StringID:68("Have fun with your Jetpack!"));
    return COMMAND_OK;
}