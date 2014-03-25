GetVehicleColor(modelID, &color1, &color2)
{
	if (modelID < 400 || modelID > 611)
	{
		return false;
	}

	new arrayIndex = modelID - 400;
	new maxColorIndex = -1;
	Count(colorIndex, MAX_VEHICLE_COLORS)
	{
		if (g_vehicleColors[arrayIndex][colorIndex][0] == -1 || g_vehicleColors[arrayIndex][colorIndex][1] == -1)
		{
			break;
		}
		maxColorIndex = colorIndex;
	}

	if (maxColorIndex < 0)
	{
		return false;
	}

	new randomColorIndex = random(maxColorIndex + 1);// random returns a value between 0 and max (Excluding the max value) -> maxColorIndex + 1 will return a value between 0 and maxColorIndex

	color1 = g_vehicleColors[arrayIndex][randomColorIndex][0];
	color2 = g_vehicleColors[arrayIndex][randomColorIndex][1];

	return true;
}