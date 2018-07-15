forward OnGarageVehiclePartsLoaded(playerID);
public OnGarageVehiclePartsLoaded(playerID)
{
    new rows;
    cache_get_row_count(rows);
    Count(row, rows)
    {
        new vehicleIndex = PVar:playerID[GARAGE_VEHICLE_ID] - 1;

        new type[16];
        cache_get_value_name(row, "type", type);
        new typeIndex = GetTuningPartByName(type);

        cache_get_value_int(row, "value", g_vehicleTuningParts[vehicleIndex][typeIndex][E_VEHICLE_TUNINGPART_VALUE]);
    }

    UpdateVehicleTuningParts(PVar:playerID[GARAGE_VEHICLE_ID]);
    UpdateVehicleSpeedMultiplier(PVar:playerID[GARAGE_VEHICLE_ID]);

    PVar:playerID[GARAGE_VEHICLE_LOADING] = false;
}