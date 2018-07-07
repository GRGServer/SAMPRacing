public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
    VehicleProperty:vehicleid[COLOR1] = color1;
    VehicleProperty:vehicleid[COLOR2] = color2;
    SaveVehicle(vehicleid);
}