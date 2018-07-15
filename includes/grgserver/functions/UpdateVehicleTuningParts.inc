UpdateVehicleTuningParts(vehicleID)
{
    Count(partIndex, MAX_TUNINGPARTTYPES)
    {
        UpdateVehicleTuningPart(vehicleID, partIndex);
    }
}