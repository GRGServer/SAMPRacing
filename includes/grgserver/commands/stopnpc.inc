PCMD:stopnpc[ISADMIN](playerID, params[], StringID:197("Stop the NPC"))
{
	DestroyVehicle(g_car_LSTest1);
	DestroyVehicle(g_car_LSTest2);
	DestroyVehicle(g_car_LSTest3);
	return COMMAND_OK;
}