ReadPosition(vehicleid)
{
    new Float:LReadX, Float:LReadY, Float:LReadZ;
    GetVehiclePos(vehicleid, LReadX, LReadY, LReadZ);
	VehPosX[vehicleid]=LReadX; VehPosY[vehicleid]=LReadY; VehPosZ[vehicleid]=LReadZ;
}