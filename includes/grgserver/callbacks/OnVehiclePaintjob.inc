public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	VehicleProperty:vehicleid[PAINTJOBID] = paintjobid;
	SaveVehicle(vehicleid);
}