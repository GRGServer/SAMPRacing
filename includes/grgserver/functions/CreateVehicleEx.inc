/**
 * <summary>
 *	Create a new vehicle at the specified position and with the specified properties.
 * </summary>
 *
 * <param name="modelID">
 *	The ID of the vehicle model which should be spawned.
 * </param>
 *
 * <param name="posX">
 *	The X-coordinate for the vehicle.
 * </param>
 *
 * <param name="posY">
 *	The Y-coordinate for the vehicle.
 * </param>
 *
 * <param name="posZ">
 *	The Z-coordinate for the vehicle.
 * </param>
 *
 * <param name="angle">
 *	The facing angle (Z rotation) of the vehicle.
 * </param>
 *
 * <param name="color1">
 *	The primary color ID.
 * </param>
 *
 * <param name="color2">
 *	The secondary color ID.
 * </param>
 *
 * <param name="isStatic">
 *	<item name="true">Use AddStaticVehicleEx for creating the vehicle (Only possible in OnGameModeInit and OnFilterScriptInit)</item>
 *	<item name="false">Use CreateVehicle for creating the vehicle (Can not spawn some trains)</item>
 * </param>
 *
 * <remarks>
 *	Vehicles with model ID 537 (Freight) and 538 (Streak) are only created if isStatic is set to true!
 * </remarks>
 */

CreateVehicleEx(modelID, Float:posX, Float:posY, Float:posZ, Float:angle, color1, color2, isStatic)
{
	if (modelID >= 400 && modelID <= 611)
	{
		new vehicleID;
		new newColor1 = color1;
		new newColor2 = color2;

		if (color1 == -1 || color2 == -1)
		{
			newColor1 = random(128);
			newColor2 = random(128);
		}

		if (isStatic)
		{
			vehicleID = AddStaticVehicle(modelID, posX, posY, posZ, angle, newColor1, newColor2);
		}
		else
		{
			if (modelID == 537 || modelID == 538)// We can not spawn Freight and Streak using CreateVehicle
			{
				return INVALID_VEHICLE_ID;
			}
			vehicleID = CreateVehicle(modelID, posX, posY, posZ, angle, newColor1, newColor2, -1);
		}

		if (!vehicleID || vehicleID == INVALID_VEHICLE_ID)
		{
			return INVALID_VEHICLE_ID;
		}

		SetVehicleParamsEx(vehicleID, false, false, false, false, false, false, false);

		Count(vehiclePropertyID, sizeof(g_vehicles[]))
		{
			g_vehicles[vehicleID][E_VEHICLE:vehiclePropertyID] = 0;
		}

		g_vehicles[vehicleID][E_VEHICLE_COLOR1] = color1;
		g_vehicles[vehicleID][E_VEHICLE_COLOR2] = color2;
		g_vehicles[vehicleID][E_VEHICLE_CURRENTCOLOR1] = newColor1;
		g_vehicles[vehicleID][E_VEHICLE_CURRENTCOLOR2] = newColor2;

		return vehicleID;
	}

	return INVALID_VEHICLE_ID;
}