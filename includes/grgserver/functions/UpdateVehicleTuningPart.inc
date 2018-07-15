UpdateVehicleTuningPart(vehicleID, part)
{
    new vehicleIndex = vehicleID - 1;

    Count(objectIndex, MAX_TUNINGPART_ITEMS)
    {
        new objectID = g_vehicleTuningParts[vehicleIndex][part][E_VEHICLE_TUNINGPART_OBJID][objectIndex];

        if (IsValidDynamicObject(objectID))
        {
            DestroyDynamicObject(objectID);
        }

        g_vehicleTuningParts[vehicleIndex][part][E_VEHICLE_TUNINGPART_OBJID][objectIndex] = 0;
    }

    new newPartValue = g_vehicleTuningParts[vehicleIndex][part][E_VEHICLE_TUNINGPART_VALUE];

    if (!newPartValue)
    {
        return;
    }

    new vehicleModelID = GetVehicleModel(vehicleID);

    if (!vehicleModelID)
    {
        return;
    }

    new tuningPartIndex = g_vehicleModels[vehicleModelID - 400][E_VEHICLEMODEL_TUNINGPARTS][newPartValue];

    if (tuningPartIndex == -1)
    {
        return;
    }

    CreateTuningPartObject(vehicleID, tuningPartIndex);
}