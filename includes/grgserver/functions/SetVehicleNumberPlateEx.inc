SetVehicleNumberPlateEx(vehicleID, numberPlate[])
{
    strdel(VehicleProperty:vehicleID[NUMBERPLATE], 0, STRINGLENGTH_NUMBERPLATE);
    strcat(VehicleProperty:vehicleID[NUMBERPLATE], numberPlate, STRINGLENGTH_NUMBERPLATE);
    SetVehicleNumberPlate(vehicleID, numberPlate);
}