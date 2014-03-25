PCMD:startnpc[ISADMIN](playerID, params[], StringID:195("Start the NPC"))
{
	g_car_LSTest1 = CreateVehicle(445, 2073.809814, -1819.895751, 13.279934, 88.126510 , 10, 1, -1);
	g_car_LSTest2 = CreateVehicle(401, 2074.655273, -1814.141235, 13.115847, 90.339157, 10, 1, -1);
	g_car_LSTest3 = CreateVehicle(496, 2073.659179, -1805.274658, 13.219514, 89.845085, 10, 1, -1);
	return COMMAND_OK;
}