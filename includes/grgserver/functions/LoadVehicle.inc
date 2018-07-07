LoadVehicle(row, Float:posX, Float:posY, Float:posZ, Float:angle)
{
    new modelID;
    new color1;
    new color2;
    cache_get_value_int(row, "modelId", modelID);
    cache_get_value_int(row, "color1", color1);
    cache_get_value_int(row, "color2", color2);

    new vehicleID = CreateVehicleEx(modelID, posX, posY, posZ, angle, color1, color2);
    if (vehicleID == INVALID_VEHICLE_ID)
    {
        new id;
        cache_get_value_int(row, "id", id);
        printf("  Unable to load vehicle %d (row %d)", id, row);
        return INVALID_VEHICLE_ID;
    }

    new Float:health;
    cache_get_value_float(row, "health", health);
    SetVehicleHealth(vehicleID, health);

    new paintjobID;
    cache_get_value_int(row, "paintjobId", paintjobID);
    ChangeVehiclePaintjob(vehicleID, paintjobID);

    new numberPlate[STRINGLENGTH_NUMBERPLATE];
    cache_get_value(row, "numberPlate", numberPlate, STRINGLENGTH_NUMBERPLATE);
    SetVehicleNumberPlateEx(vehicleID, numberPlate);

    cache_get_value_int(row, "mileage", VehicleProperty:vehicleID[MILEAGE]);
    cache_get_value_int(row, "userId", VehicleProperty:vehicleID[USERID]);
    cache_get_value_int(row, "id", VehicleProperty:vehicleID[SAVEID]);
    cache_get_value_int(row, "garageId", VehicleProperty:vehicleID[GARAGEID]);

    return vehicleID;
}