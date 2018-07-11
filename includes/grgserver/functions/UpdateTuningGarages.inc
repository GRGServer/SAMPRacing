UpdateTuningGarages()
{
    DestroyPickupsOfType(PICKUPTYPE_TUNING_GARAGE);

    Foreach(tuningGarageNumber, g_tuningGarages)
    {
        if (!g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_ID])
        {
            continue;
        }

        g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_PICKUP_ID] = AddPickup(PICKUPTYPE_TUNING_GARAGE, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ], tuningGarageNumber);
    }
}