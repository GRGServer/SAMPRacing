EnterGarage(playerID, garageNumber)
{
    PVar:playerID[ALLOWCMDS] = false;

    new vehicleID = GetPlayerVehicleID(playerID);
    if (vehicleID && VehicleProperty:vehicleID[SAVEID])
    {
        MySQLFormat("UPDATE `vehicles` SET `garageId` = %d WHERE `id` = %d", g_garages[garageNumber][E_GARAGE_ID], VehicleProperty:vehicleID[SAVEID]);
        mysql_query(g_mysql, g_sqlQuery);

        PVar:playerID[GARAGE_VEHICLE_SAVEID] = VehicleProperty:vehicleID[SAVEID] - 1;

        DestroyVehicleEx(vehicleID);
    }
    else
    {
        PVar:playerID[GARAGE_VEHICLE_SAVEID] = 0;
    }

    PVar:playerID[GARAGE_NUMBER] = garageNumber;

    MySQLFormat("SELECT `id`, `modelId`, `numberPlate`, `mileAge`, `userId`, `garageId`, `health`, `color1`, `color2`, `paintjobId` FROM `vehicles` WHERE `userId` = %d AND `garageId` = %d", PVar:playerID[USERID], g_garages[PVar:playerID[GARAGE_NUMBER]][E_GARAGE_ID]);
    mysql_pquery(g_mysql, g_sqlQuery, "OnGarageVehiclesLoaded", "d", playerID);
}