forward OnGarageVehicleComponentsLoaded(playerID);
public OnGarageVehicleComponentsLoaded(playerID)
{
	Count(row, cache_get_row_count())
	{
		new componentID = cache_get_field_content_int(row, "componentId");
		if (componentID)
		{
			AddVehicleComponent(PVar:playerID[GARAGE_VEHICLE_ID], componentID);
		}
	}

	PVar:playerID[GARAGE_VEHICLE_LOADING] = false;
}