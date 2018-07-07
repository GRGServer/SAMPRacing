PCMD:setracelevel[ISADMIN](playerID, params[], StringID:178("Set the required level of a race"))
{
    new raceID;
    new level;
    if (sscanf(params, "dd", raceID, level))
    {
        CmdUsageMsg(playerID, "addracecp", "RaceID", "Level");
        return COMMAND_USAGE;
    }

    if (raceID < 0 || raceID >= MAX_RACES)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:157("The Race ID must be between 0 and %d!"), MAX_RACES - 1);
        return COMMAND_ERROR;
    }

    if (level < 1)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:180("The level can not be bellow 1!"));
        return COMMAND_ERROR;
    }

    g_races[raceID][E_RACE_LEVEL] = level;

    SaveRaces();

    SendClientMessageEx(playerID, COLOR_INFO, StringID:181("The level of the race has been changed"));

    return COMMAND_OK;
}