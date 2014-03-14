DistanceToPoint(vehicleid)
{
	new Float:LPlayerX, Float:LPlayerY, Float:LPlayerZ, Float:LReadPos;
	GetVehiclePos(vehicleid, LPlayerX, LPlayerY, LPlayerZ);
	LReadPos = floatsqroot(floatpower(floatabs(floatsub(LPlayerX, VehPosX[vehicleid])), 2)+floatpower(floatabs(floatsub(LPlayerY, VehPosY[vehicleid])), 2)+floatpower(floatabs(floatsub(LPlayerZ, VehPosZ[vehicleid])), 2));
	return floatround(LReadPos);
}
