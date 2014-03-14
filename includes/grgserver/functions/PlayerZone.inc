PlayerZone(playerid, zone[])
{
	new ReadTmpZone[MAX_ZONE_NAME];
    GetPlayer3DZone(playerid, ReadTmpZone, sizeof(ReadTmpZone)); for(new i = 0; i != sizeof(SanAndreasZones); i++)
	{
		if(strfind(ReadTmpZone, zone, true) != -1)
		return 1;
	}
	return 0;
}