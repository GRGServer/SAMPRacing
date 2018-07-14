CreateVehicleEx(modelID, Float:posX, Float:posY, Float:posZ, Float:angle, color1, color2)
{
    if (modelID >= 400 && modelID <= 611)
    {
        new vehicleID;

        if (color1 == -1 || color2 == -1)
        {
            color1 = random(128);
            color2 = random(128);
        }

        if (modelID == 537 || modelID == 538)// We can not spawn Freight and Streak using CreateVehicle
        {
            return INVALID_VEHICLE_ID;
        }
        vehicleID = CreateVehicle(modelID, posX, posY, posZ, angle, color1, color2, -1);

        if (!vehicleID || vehicleID == INVALID_VEHICLE_ID)
        {
            return INVALID_VEHICLE_ID;
        }

        Count(field, sizeof(g_vehicles[]))
        {
            g_vehicles[vehicleID - 1][E_VEHICLE:field] = 0;
        }

        VehicleProperty:vehicleID[COLOR1] = color1;
        VehicleProperty:vehicleID[COLOR2] = color2;
        VehicleProperty:vehicleID[SPEEDMULTIPLIER] = 1;

        return vehicleID;
    }

    return INVALID_VEHICLE_ID;
}