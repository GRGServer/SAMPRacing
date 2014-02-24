ACMD:savepos(playerID, params[], StringID:42("Save your current position to a file"))
{
	new File:file = fopen("positions.txt", io_append);
	if (file)
	{
		new string[256];
		new Float:posX;
		new Float:posY;
		new Float:posZ;
		new Float:angle;

		Format:string("[%s] ", GetPlayerNameEx(playerID));

		if (IsPlayerInAnyVehicle(playerID))
		{
			new vehicleID = GetPlayerVehicleID(playerID);
			GetVehiclePos(vehicleID, posX, posY, posZ);
			GetVehicleZAngle(vehicleID, angle);
			Format:string("%f x %f x %f x %f (int %d) (model %d)", posX, posY, posZ, angle, GetPlayerInterior(playerID), GetVehicleModel(vehicleID));
		}
		else
		{
			GetPlayerPos(playerID, posX, posY, posZ);
			GetPlayerFacingAngle(playerID, angle);
			Format:string("%f x %f x %f x %f (int %d)", posX, posY, posZ, angle, GetPlayerInterior(playerID));
		}

		if (StrNotNull(params))
		{
			Format:string("%s %s", string, params);
		}

		strcat(string, "\n");

		fwrite(file, string);
		fclose(file);

		SendClientMessageEx(playerID, COLOR_INFO, StringID:48("Position saved"));
		return COMMAND_OK;
	}

	return COMMAND_ERROR;
}