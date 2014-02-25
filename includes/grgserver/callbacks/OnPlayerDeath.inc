public OnPlayerDeath(playerid, killerid, reason)
{
	SendDeathMessage(killerid, playerid, reason);

	GetPlayerPos(playerid, PVar:playerid[DEATH_POSX], PVar:playerid[DEATH_POSY], PVar:playerid[DEATH_POSZ]);
	PVar:playerid[SPAWNTYPE] = SPAWNTYPE_DEATH;
}