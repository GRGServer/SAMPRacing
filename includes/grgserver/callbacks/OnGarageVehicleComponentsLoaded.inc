forward OnGarageVehicleComponentsLoaded(playerID);
public OnGarageVehicleComponentsLoaded(playerID)
{
    new rows;
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new componentID;
        cache_get_value_int(row, "componentId", componentID);
        if (componentID)
        {
            AddVehicleComponent(PVar:playerID[GARAGE_VEHICLE_ID], componentID);
        }
    }

    MySQLFormat("SELECT * FROM `vehicletuningparts` WHERE `vehicleId` = %d", PVar:playerID[GARAGE_VEHICLE_SAVEID]);
    mysql_pquery(g_mysql, g_sqlQuery, "OnGarageVehiclePartsLoaded", "d", playerID);
}