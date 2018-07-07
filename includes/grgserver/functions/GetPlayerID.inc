GetPlayerID(name[])
{
    PlayerLoop(playerID)
    {
        if (IsStr(GetPlayerNameEx(playerID), name))
        {
            return playerID;
        }
    }

    return INVALID_PLAYER_ID;
}