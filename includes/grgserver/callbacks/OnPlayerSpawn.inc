public OnPlayerSpawn(playerid)
{
	// Spawned after login/register
	if (PVar:playerid[FIRSTSPAWN])
	{
		PVar:playerid[FIRSTSPAWN] = false;

		new Cache:result = mysql_query_format(true, "SELECT `posX`, `posY`, `posZ`, `angle`, `interior` FROM `users` WHERE `id` = %d", PVar:playerid[USERID]);
		new Float:posX = cache_get_field_content_float(0, "posX");
		new Float:posY = cache_get_field_content_float(0, "posY");
		new Float:posZ = cache_get_field_content_float(0, "posZ");
		new Float:angle = cache_get_field_content_float(0, "angle");
		new interior = cache_get_field_content_int(0, "interior");
		cache_delete(result);

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