SavePlayer(playerID)
{
	if (IsLoggedIn(playerID))
	{
		MySQLFormat("UPDATE `users` SET `money` = %d WHERE `id` = %d", GetPlayerMoney(playerID), PVar:playerID[USERID]);
		mysql_pquery(1, g_sqlQuery);

		new Float:posX;
		new Float:posY;
		new Float:posZ;
		new Float:angle;
		GetPlayerPos(playerID, posX, posY, posZ);
		GetPlayerFacingAngle(playerID, angle);

		if (posX != 0 || posY != 0 || posZ != 0)
		{
			MySQLFormat("UPDATE `users` SET `posX` = '%f', `posY` = '%f', `posZ` = '%f', `angle` = '%f', `interior` = '%d' WHERE `id` = %d", posX, posY, posZ, angle, GetPlayerInterior(playerID), PVar:playerID[USERID]);
			mysql_pquery(1, g_sqlQuery);
		}
	}
}