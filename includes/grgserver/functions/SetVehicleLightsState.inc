SetVehicleLightsState(vehicleID, newState)
{
	new engine;
	new lights;
	new alarm;
	new doors;
	new bonnet;
	new boot;
	new objective;
	GetVehicleParamsEx(vehicleID, engine, lights, alarm, doors, bonnet, boot, objective);
	if (lights != newState)
	{
		SetVehicleParamsEx(vehicleID, engine, newState, alarm, doors, bonnet, boot, objective);
		if (newState)
		{
			if (VehicleProperty:vehicleID[FRONTLIGHTID])
			{
				AddNeonLight(vehicleID, NEONTYPE_FRONT_LEFT, VehicleProperty:vehicleID[FRONTLIGHTID] - 1);
				AddNeonLight(vehicleID, NEONTYPE_FRONT_RIGHT, VehicleProperty:vehicleID[FRONTLIGHTID] - 1);
			}
		}
		else
		{
			Count(colorID, LIGHTOBJECT_MAXCOLORS)
			{
				if (vehicleLightObjects[vehicleID][NEONTYPE_FRONT_LEFT][colorID])
				{
					DestroyDynamicObject(vehicleLightObjects[vehicleID][NEONTYPE_FRONT_LEFT][colorID]);
					vehicleLightObjects[vehicleID][NEONTYPE_FRONT_LEFT][colorID] = 0;
				}
				if (vehicleLightObjects[vehicleID][NEONTYPE_FRONT_RIGHT][colorID])
				{
					DestroyDynamicObject(vehicleLightObjects[vehicleID][NEONTYPE_FRONT_RIGHT][colorID]);
					vehicleLightObjects[vehicleID][NEONTYPE_FRONT_RIGHT][colorID] = 0;
				}
			}
			UpdateObjectsForAllPlayers();
		}
	}
}