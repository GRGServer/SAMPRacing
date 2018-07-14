forward OnPlayerDataLoaded(playerID);
public OnPlayerDataLoaded(playerID)
{
    new language[10];
    cache_get_value(0, "language", language, 10);
    PVar:playerID[LANGUAGE] = GetLanguageID(language);

    new isAdmin;
    cache_get_value_int(0, "isAdmin", isAdmin);
    PVar:playerID[ISADMIN] = isAdmin;

    PVar:playerID[ALLOWCMDS] = true;

    ResetPlayerMoney(playerID);

    new money;
    cache_get_value_int(0, "money", money);
    GivePlayerMoney(playerID, money);

    new score;
    cache_get_value_int(0, "level", score);
    SetPlayerScore(playerID, score);

    CreatePlayerTextDraws(playerID);

    UpdateMapIcons(playerID);

    new Float:posX;
    new Float:posY;
    new Float:posZ;
    new Float:angle;
    new interior;

    cache_get_value_float(0, "posX", posX);
    cache_get_value_float(0, "posY", posY);
    cache_get_value_float(0, "posZ", posZ);
    cache_get_value_float(0, "angle", angle);
    cache_get_value_int(0, "interior", interior);

    cache_get_value_int(0, "skin", PVar:playerID[SKIN]);

    TogglePlayerControllable(playerID, true);
    SetPlayerSpawn(playerID, SPAWNTYPE_DEFAULT, posX, posY, posZ, angle, interior);
    SpawnPlayer(playerID);
}