CreateTuningPartObject(vehicleID, tuningPartIndex)
{
    new vehicleIndex = vehicleID - 1;
    new modelID = g_tuningParts[tuningPartIndex][E_TUNINGPART_MODELID];
    new part = g_tuningParts[tuningPartIndex][E_TUNINGPART_TYPE];

    Count(objectIndex, MAX_TUNINGPART_ITEMS)
    {
        new Float:offsetX = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_X][objectIndex];
        new Float:offsetY = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_Y][objectIndex];
        new Float:offsetZ = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_Z][objectIndex];
        new Float:rotationX = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_X][objectIndex];
        new Float:rotationY = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_Y][objectIndex];
        new Float:rotationZ = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_Z][objectIndex];

        if (!offsetX && !offsetY && !offsetZ)
        {
            continue;
        }

        new objectID = CreateDynamicObject(modelID, 0, 0, 0, 0, 0, 0);

        AttachDynamicObjectToVehicle(objectID, vehicleID, offsetX, offsetY, offsetZ, rotationX, rotationY, rotationZ);

        g_vehicleTuningParts[vehicleIndex][part][E_VEHICLE_TUNINGPART_OBJID][objectIndex] = objectID;
    }
}