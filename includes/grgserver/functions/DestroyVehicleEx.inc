DestroyVehicleEx(vehicleID)
{
	DestroyVehicle(vehicleID);

	Count(field, sizeof(g_vehicles[]))
	{
		g_vehicles[vehicleID - 1][E_VEHICLE:field] = 0;
	}
}