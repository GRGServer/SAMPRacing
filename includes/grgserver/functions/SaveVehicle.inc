SaveVehicle(vehicleID, insertNew = false)
{
	if (insertNew)
	{
		MySQLFormat("INSERT INTO `vehicles` (`modelId`, `userId`) VALUES(%d, %d)", GetVehicleModel(vehicleID), VehicleProperty:vehicleID[USERID]);
		mysql_pquery(1, g_sqlQuery, "OnVehicleInserted", "d", vehicleID);
	}
	else if (VehicleProperty:vehicleID[SAVEID])
	{
		new Float:posX;
		new Float:posY;
		new Float:posZ;
		new Float:angle;
		new Float:health;
		GetVehiclePos(vehicleID, posX, posY, posZ);
		GetVehicleZAngle(vehicleID, angle);
		GetVehicleHealth(vehicleID, health);
		MySQLFormat("UPDATE `vehicles` SET `modelID` = %d, `userID` = %d, `posX` = %f, `posY` = %f, `posZ` = %f, `angle` = %f, `health` = %f, `mileage` = %d, `numberPlate` = '%e' WHERE `id` = %d", GetVehicleModel(vehicleID), VehicleProperty:vehicleID[USERID], posX, posY, posZ, angle, health, VehicleProperty:vehicleID[MILEAGE], VehicleProperty:vehicleID[NUMBERPLATE], VehicleProperty:vehicleID[SAVEID]);
		mysql_pquery(1, g_sqlQuery);

		MySQLFormat("UPDATE `vehicles` SET `color1` = %d, `color2` = %d, `paintjobId` = %d WHERE `id` = %d", VehicleProperty:vehicleID[COLOR1], VehicleProperty:vehicleID[COLOR2], VehicleProperty:vehicleID[PAINTJOBID], VehicleProperty:vehicleID[SAVEID]);
		mysql_pquery(1, g_sqlQuery);

		MySQLFormat("UPDATE `vehiclecomponents` SET `componentId` = %d WHERE `vehicleId` = %d AND `slot` = %d", GetVehicleComponentInSlot(vehicleID, CARMODTYPE_NITRO), VehicleProperty:vehicleID[SAVEID], CARMODTYPE_NITRO);// Nitro changes without beeing in a mod shop
		mysql_pquery(1, g_sqlQuery);
	}
}