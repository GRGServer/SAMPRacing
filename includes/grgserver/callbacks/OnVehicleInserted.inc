forward OnVehicleInserted(vehicleID);
public OnVehicleInserted(vehicleID)
{
    VehicleProperty:vehicleID[SAVEID] = cache_insert_id();

    Count(slot, MAX_VEHICLECOMPONENT_SLOTS)
    {
        MySQLFormat("INSERT INTO `vehiclecomponents` (`vehicleId`, `slot`, `componentId`) VALUES(%d, %d, %d)", VehicleProperty:vehicleID[SAVEID], slot, GetVehicleComponentInSlot(vehicleID, slot));
        mysql_pquery(g_mysql, g_sqlQuery);
    }
}