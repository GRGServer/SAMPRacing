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
    result = mysql_query(g_mysql, "SELECT * FROM `vehicles`");
    new rows;
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new garageID;
        cache_get_value_int(row, "garageId", garageID);

        // Skip vehicles in garages
        if (garageID)
        {
            continue;
        }

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

    printf("  %d vehicle components added", count);
}