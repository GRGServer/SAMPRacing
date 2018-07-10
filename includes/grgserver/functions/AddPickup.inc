AddPickup(type, Float:posX, Float:posY, Float:posZ, linkID)
{
    new modelID;
    switch (type)
    {
        case PICKUPTYPE_GARAGE_BOUGHT:
        {
            modelID = 1272;
        }
        case PICKUPTYPE_GARAGE_FREE:
        {
            modelID = 1273;
        }
        case PICKUPTYPE_HOSPITAL:
        {
            modelID = 1240;
        }
        case PICKUPTYPE_RACE:
        {
            modelID = 19130;
        }
        case PICKUPTYPE_VEHICLESHOP:
        {
            modelID = 1274;
        }
    }

    new pickupID = CreateDynamicPickup(modelID, 1, posX, posY, posZ);
    if (pickupID == -1)
    {
        printf("Unable to add pickup (Limit reached?)");
        return -1;
    }

    g_pickups[pickupID][E_PICKUP_TYPE] = type;
    g_pickups[pickupID][E_PICKUP_LINKID] = linkID;

    return pickupID;
}