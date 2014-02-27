CheckNumberPlate(string[])
{
	Foreach(index, g_vehicles)
	{
		if (IsStr(g_vehicles[index][E_VEHICLE_NUMBERPLATE], string))
		{
			return false;
		}
	}

	return true;
}