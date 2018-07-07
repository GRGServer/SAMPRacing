CMD:skin(playerID, params[], StringID:245("Change your skin"))
{
    new skin;

    if (sscanf(params, "d", skin))
	{
        CmdUsageMsg(playerID, "skin", "SkinID");
		return COMMAND_USAGE;
    }

    if (skin < 0 || skin > 311)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:246("The skin ID must be between 0 and 311!"));
	    return COMMAND_ERROR;
    }

    PVar:playerID[SKIN] = skin;
    SetPlayerSkin(playerID, skin);

    MySQLFormat("UPDATE `users` SET `skin` = %d WHERE `id` = %d", skin, PVar:playerID[USERID]);
	mysql_pquery(g_mysql, g_sqlQuery);

    return COMMAND_OK;
}