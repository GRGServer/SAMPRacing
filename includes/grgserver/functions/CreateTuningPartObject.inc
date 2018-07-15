CreateTuningPartObject(vehicleID, tuningPartIndex)
{
    new vehicleIndex = vehicleID - 1;
    new modelID = g_tuningParts[tuningPartIndex][E_TUNINGPART_MODELID];
    new part = g_tuningParts[tuningPartIndex][E_TUNINGPART_TYPE];

    Count(objectIndex, MAX_TUNINGPART_ITEMS)
    {
        new Float:posX = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_X][objectIndex];
        new Float:posY = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_Y][objectIndex];
        new Float:posZ = g_tuningParts[tuningPartIndex][E_TUNINGPART_OFFSET_Z][objectIndex];
        new Float:rotX = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_X][objectIndex];
        new Float:rotY = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_Y][objectIndex];
        new Float:rotZ = g_tuningParts[tuningPartIndex][E_TUNINGPART_ROTATION_Z][objectIndex];

        if (!posX && !posY && !posZ)
        {
            continue;
        }

        new objectID = CreateDynamicObject(modelID, posX, posY, posZ, rotX, rotY, rotZ);

        g_vehicleTuningParts[vehicleIndex][part][E_VEHICLE_TUNINGPART_OBJID][objectIndex] = objectID;
    }
}