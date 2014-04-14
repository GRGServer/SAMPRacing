SetVehicleNumberPlateEx(vehicleID, numberPlate[])
{
	strcat(VehicleProperty:vehicleID[NUMBERPLATE], numberPlate, STRINGLENGTH_NUMBERPLATE);
	SetVehicleNumberPlate(vehicleID, numberPlate);
}