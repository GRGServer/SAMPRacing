Timer:EverySecond()
{
	new hour;
	new minute;
	gettime(hour, minute);

	SetWorldTime(hour);

	FormatNew:clockString[6]("%02d:%02d", hour, minute);
	TextDrawSetString(g_textDrawClock, clockString);

	// Writer player stats
	new playerStatsString[100];
	new Float:posX;
	new Float:posY;
	new Float:posZ;
	new vehicleModelID;
	new File:playerStatsFile = fopen("playerstats.dat", io_write);
	if (playerStatsFile)
	{
		PlayerLoop(playerID)
		{
			vehicleModelID = 0;
			if (IsPlayerInAnyVehicle(playerID))
			{
				vehicleModelID = GetVehicleModel(GetPlayerVehicleID(playerID));
			}
			GetPlayerPos(playerID, posX, posY, posZ);
			Format:playerStatsString("%d\t%s\t%f\t%f\t%f\t%d\t%d\n", playerID, GetPlayerNameEx(playerID), posX, posY, posZ, GetPlayerInterior(playerID), vehicleModelID);
			fwrite(playerStatsFile, playerStatsString);
		}
		fclose(playerStatsFile);
	}
}