SaveVehicle(vehicleID)
{
	if (VehicleProperty:vehicleID[SAVEID])
	{
		new Float:posX;
		new Float:posY;
		new Float:posZ;
		new Float:angle;
		new Float:health;
		GetVehiclePos(vehicleID, posX, posY, posZ);
		GetVehicleZAngle(vehicleID, angle);
		GetVehicleHealth(vehicleID, health);
		mysql_query_format(false, "UPDATE `vehicles` SET `modelID` = %d, `userID` = %d, `posX` = %f, `posY` = %f, `posZ` = %f, `angle` = %f, `health` = %f, `mileage` = %d WHERE `id` = %d", GetVehicleModel(vehicleID), VehicleProperty:vehicleID[USERID], posX, posY, posZ, angle, health, VehicleProperty:vehicleID[MILEAGE], VehicleProperty:vehicleID[SAVEID]);

		mysql_query_format(false, "UPDATE `vehicles` SET `color1` = %d, `color2` = %d, `paintjobId` = %d WHERE `id` = %d", VehicleProperty:vehicleID[COLOR1], VehicleProperty:vehicleID[COLOR2], VehicleProperty:vehicleID[PAINTJOBID], VehicleProperty:vehicleID[SAVEID]);
	}
}