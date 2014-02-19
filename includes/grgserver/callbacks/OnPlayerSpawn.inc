public OnPlayerSpawn(playerid)
{
	// Spawned after login/register
	if (PVar:playerid[FIRSTSPAWN])
	{
		PVar:playerid[FIRSTSPAWN] = false;

		MySQLQuery("SELECT `posX`, `posY`, `posZ`, `angle`, `interior` FROM `users` WHERE `id` = %d", PVar:playerid[USERID]);
		mysql_store_result();
		new Float:posX = floatstr(GetMySQLField("posX"));
		new Float:posY = floatstr(GetMySQLField("posY"));
		new Float:posZ = floatstr(GetMySQLField("posZ"));
		new Float:angle = floatstr(GetMySQLField("angle"));
		new interior = strval(GetMySQLField("interior"));
		mysql_free_result();

		// Last position of player is 0 x 0 x 0 which means the player was never spawned -> Spawn at configured default location
		if (!posX && !posY && !posZ)
		{
			posX = SPAWN_POSX;
			posY = SPAWN_POSY;
			posZ = SPAWN_POSZ;
			angle = SPAWN_ANGLE;
			interior = SPAWN_INTERIOR;
		}

		SetPlayerPos(playerid, posX, posY, posZ);
		SetPlayerFacingAngle(playerid, angle);
		SetPlayerInterior(playerid, interior);
	}
	else
	{
		// TODO: Spawn at the nearest hospital?
	}
}