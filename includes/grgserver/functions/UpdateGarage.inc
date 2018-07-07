UpdateGarage(garageNumber)
{
    if (g_garages[garageNumber][E_GARAGE_PICKUP_ID] != -1)
    {
        DestroyPickup(g_garages[garageNumber][E_GARAGE_PICKUP_ID]);
    }

    new pickupType;
    if (g_garages[garageNumber][E_GARAGE_USERID])
    {
        pickupType = PICKUPTYPE_GARAGE_BOUGHT;
    }
    else
    {
        pickupType = PICKUPTYPE_GARAGE_FREE;
    }

    g_garages[garageNumber][E_GARAGE_PICKUP_ID] = AddPickup(pickupType, g_garages[garageNumber][E_GARAGE_PICKUP_POSX], g_garages[garageNumber][E_GARAGE_PICKUP_POSY], g_garages[garageNumber][E_GARAGE_PICKUP_POSZ], garageNumber);
}