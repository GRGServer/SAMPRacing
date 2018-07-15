ReloadVehicles()
{
    print("Loading vehicles...");

    Foreach(index, g_vehicles)
    {
        Foreach(field, g_vehicles[])
        {
            g_vehicles[index][E_VEHICLE:field] = 0;
        }
    }

    new Cache:result;

    new count;
    result = mysql_query(g_mysql, "SELECT * FROM `vehicles` WHERE `garageId` IS NULL");
    new rows;
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new Float:posX;
        new Float:posY;
        new Float:posZ;
        new Float:angle;

        cache_get_value_float(row, "posX", posX);
        cache_get_value_float(row, "posY", posY);
        cache_get_value_float(row, "posZ", posZ);
        cache_get_value_float(row, "angle", angle);

        if (LoadVehicle(row, posX, posY, posZ, angle) != INVALID_VEHICLE_ID)
        {
            count++;
        }
    }
    cache_delete(result);

    printf("  %d vehicles loaded", count);

    print("Adding vehicle components...");

    count = 0;
    result = mysql_query(g_mysql, "SELECT `vehicleId`, `componentId` FROM `vehiclecomponents` WHERE `componentId`");
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new vehicleSaveID;
        cache_get_value_int(row, "vehicleId", vehicleSaveID);
        Foreach(vehicleIndex, g_vehicles)
        {
            if (g_vehicles[vehicleIndex][E_VEHICLE_SAVEID] == vehicleSaveID)
            {
                new componentID;
                cache_get_value_int(row, "componentId", componentID);
                AddVehicleComponent(vehicleIndex + 1, componentID);
                count++;
                break;
            }
        }
    }
    cache_delete(result);

    printf("  %d vehicle components added", count);

    print("Adding vehicle tuning parts...");

    count = 0;
    result = mysql_query(g_mysql, "SELECT * FROM `vehicletuningparts`");
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new vehicleSaveID;
        cache_get_value_int(row, "vehicleId", vehicleSaveID);
        Foreach(vehicleIndex, g_vehicles)
        {
            if (g_vehicles[vehicleIndex][E_VEHICLE_SAVEID] == vehicleSaveID)
            {
                new type[16];
                cache_get_value_name(row, "type", type);
                new typeIndex = GetTuningPartByName(type);

                cache_get_value_int(row, "value", g_vehicleTuningParts[vehicleIndex][typeIndex][E_VEHICLE_TUNINGPART_VALUE]);

                count++;
                break;
            }
        }
    }
    cache_delete(result);

    Foreach(vehicleIndex, g_vehicles)
    {
        new vehicleID = vehicleIndex + 1;// Add 1 as the vehicle ID starts with 1

        UpdateVehicleTuningParts(vehicleID);
        UpdateVehicleSpeedMultiplier(vehicleID);
    }

    printf("  %d vehicle tuning parts added", count);
}