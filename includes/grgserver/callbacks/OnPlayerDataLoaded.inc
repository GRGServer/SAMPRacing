forward OnPlayerDataLoaded(playerID);
public OnPlayerDataLoaded(playerID)
{
	PVar:playerID[LANGUAGE] = GetLanguageID(GetMySQLField("language"));
	PVar:playerID[ISADMIN] = strval(GetMySQLField("isAdmin"));

	PVar:playerID[ALLOWCMDS] = true;

	ResetPlayerMoney(playerID);
	GivePlayerMoney(playerID, strval(GetMySQLField("money")));

	SetPlayerScore(playerID, strval(GetMySQLField("level")));

	CreatePlayerTextDraws(playerID);

	SetPlayerSpawn(playerID, SPAWNTYPE_DEFAULT, cache_get_field_content_float(0, "posX"), cache_get_field_content_float(0, "posY"), cache_get_field_content_float(0, "posZ"), cache_get_field_content_float(0, "angle"), cache_get_field_content_int(0, "interior"));
	SpawnPlayer(playerID);
}