ReloadVehicles()
{
	print("Loading vehicles...");

	Foreach(index, g_vehicles)
	{
		Foreach(field, g_vehicles[])
		{
			g_vehicles[index][E_VEHICLE:field] = 0;
		}
	}

	new Cache:result;

	new count;
	result = mysql_query(1, "SELECT * FROM `vehicles`");
	Count(row, cache_get_row_count())
	{
		new vehicleID = CreateVehicleEx(cache_get_field_content_int(row, "modelId"), cache_get_field_content_float(row, "posX"), cache_get_field_content_float(row, "posY"), cache_get_field_content_float(row, "posZ"), cache_get_field_content_float(row, "angle"), cache_get_field_content_int(row, "color1"), cache_get_field_content_int(row, "color2"));
		if (vehicleID == INVALID_VEHICLE_ID)
		{
			printf("  Unable to create vehicle %d", cache_get_field_content_int(row, "id"));
		}
		else
		{
			SetVehicleHealth(vehicleID, cache_get_field_content_float(row, "health"));
			ChangeVehiclePaintjob(vehicleID, cache_get_field_content_int(row, "paintjobId"));
			VehicleProperty:vehicleID[MILEAGE] = cache_get_field_content_int(row, "mileage");
			count++;
		}
	}
	cache_delete(result);

	printf("  %d vehicles loaded", count);

	print("Adding vehicle components...");

	count = 0;
	result = mysql_query(1, "SELECT * FROM `vehiclecomponents`");
	Count(row, cache_get_row_count())
	{
		new vehicleSaveID = cache_get_field_content_int(row, "vehicleId");
		Foreach(vehicleIndex, g_vehicles)
		{
			if (g_vehicles[vehicleIndex][E_VEHICLE_SAVEID] == vehicleSaveID)
			{
				AddVehicleComponent(vehicleIndex + 1, cache_get_field_content_int(row, "componentId"));
				count++;
				break;
			}
		}
	}

	printf("  %d vehicle components added", count);
}