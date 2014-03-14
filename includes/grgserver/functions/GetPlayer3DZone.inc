GetPlayer3DZone(playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
 	for(new i = 0; i != sizeof(SanAndreasZones); i++ )
	{
		if(x >= SanAndreasZones[i][Zone_Area][0] && x <= SanAndreasZones[i][Zone_Area][3] && y >= SanAndreasZones[i][Zone_Area][1] && y <= SanAndreasZones[i][Zone_Area][4] && z >= SanAndreasZones[i][Zone_Area][2] && z <= SanAndreasZones[i][Zone_Area][5])
		{
			return format(zone, len, SanAndreasZones[i][Zone_Name], 0);
		}
	}
	return 0;
}