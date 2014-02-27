SaveVehicle(vehicleID, insertNew = false)
{
	if (insertNew)
	{
		new Cache:result = mysql_query_format(true, "INSERT INTO `vehicles` (`modelId`, `userId`) VALUES(%d, %d)", GetVehicleModel(vehicleID), VehicleProperty:vehicleID[USERID]);
		VehicleProperty:vehicleID[SAVEID] = cache_insert_id();
		cache_delete(result);

		Count(slot, MAX_VEHICLECOMPONENT_SLOTS)
		{
			mysql_query_format(false, "INSERT INTO `vehiclecomponents` (`vehicleId`, `slot`, `componentId`) VALUES(%d, %d, %d)", VehicleProperty:vehicleID[SAVEID], slot, GetVehicleComponentInSlot(vehicleID, slot));
		}
	}

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

		mysql_query_format(false, "UPDATE `vehiclecomponents` SET `componentId` = %d WHERE `vehicleId` = %d AND `slot` = %d", GetVehicleComponentInSlot(vehicleID, CARMODTYPE_NITRO), VehicleProperty:vehicleID[SAVEID], CARMODTYPE_NITRO);// Nitro changes without beeing in a mod shop
	}
}