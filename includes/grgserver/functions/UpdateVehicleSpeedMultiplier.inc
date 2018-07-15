UpdateVehicleSpeedMultiplier(vehicleID)
{
    new modelID = GetVehicleModel(vehicleID);

    if (!modelID)
    {
        VehicleProperty:vehicleID[SPEEDMULTIPLIER] = 1;
        return;
    }

    new Float:speedMultiplier = 1;

    Count(partIndex, MAX_TUNINGPARTTYPES)
    {
        new partValue = g_vehicleTuningParts[vehicleID - 1][partIndex][E_VEHICLE_TUNINGPART_VALUE];

        if (partValue == -1)
        {
            continue;
        }

        new tuningPartIndex = g_vehicleModels[modelID - 400][E_VEHICLEMODEL_TUNINGPARTS][partValue];

        if (tuningPartIndex == -1)
        {
            continue;
        }

        speedMultiplier += g_tuningParts[tuningPartIndex][E_TUNINGPART_SPEEDMULTIPLIER];
    }

    VehicleProperty:vehicleID[SPEEDMULTIPLIER] = speedMultiplier;
}