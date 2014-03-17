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
		// Skip vehicles in garages
		if (cache_get_field_content_int(row, "garageId"))
		{
			continue;
		}

		if (LoadVehicle(row, cache_get_field_content_float(row, "posX"), cache_get_field_content_float(row, "posY"), cache_get_field_content_float(row, "posZ"), cache_get_field_content_float(row, "angle")) != INVALID_VEHICLE_ID)
		{
			count++;
		}
	}
	cache_delete(result);

	printf("  %d vehicles loaded", count);

	print("Adding vehicle components...");

	count = 0;
	result = mysql_query(1, "SELECT `vehicleId`, `componentId` FROM `vehiclecomponents` WHERE `componentId`");
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