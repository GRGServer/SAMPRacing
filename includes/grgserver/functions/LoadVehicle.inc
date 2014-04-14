LoadVehicle(row, Float:posX, Float:posY, Float:posZ, Float:angle)
{
	new vehicleID = CreateVehicleEx(cache_get_field_content_int(row, "modelId"), posX, posY, posZ, angle, cache_get_field_content_int(row, "color1"), cache_get_field_content_int(row, "color2"));
	if (vehicleID == INVALID_VEHICLE_ID)
	{
		printf("  Unable to load vehicle %d (row %d)", cache_get_field_content_int(row, "id"), row);
		return INVALID_VEHICLE_ID;
	}

	SetVehicleHealth(vehicleID, cache_get_field_content_float(row, "health"));
	ChangeVehiclePaintjob(vehicleID, cache_get_field_content_int(row, "paintjobId"));

	new numberPlate[STRINGLENGTH_NUMBERPLATE];
	cache_get_field_content(row, "numberPlate", numberPlate, 1);
	SetVehicleNumberPlateEx(vehicleID, numberPlate);

	VehicleProperty:vehicleID[MILEAGE] = cache_get_field_content_int(row, "mileage");
	VehicleProperty:vehicleID[USERID] = cache_get_field_content_int(row, "userId");
	VehicleProperty:vehicleID[SAVEID] = cache_get_field_content_int(row, "id");
	VehicleProperty:vehicleID[GARAGEID] = cache_get_field_content_int(row, "garageId");

	return vehicleID;
}