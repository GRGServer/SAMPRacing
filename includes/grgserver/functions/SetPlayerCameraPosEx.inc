SetPlayerCameraPosEx(playerID, Float:posX, Float:posY, Float:posZ, Float:lookAtX, Float:lookAtY, Float:lookAtZ, count = 3)
{
	PVar:playerID[SETCAMERA_POSX] = posX;
	PVar:playerID[SETCAMERA_POSY] = posY;
	PVar:playerID[SETCAMERA_POSZ] = posZ;
	PVar:playerID[SETCAMERA_LOOKATX] = lookAtX;
	PVar:playerID[SETCAMERA_LOOKATY] = lookAtY;
	PVar:playerID[SETCAMERA_LOOKATZ] = lookAtZ;
	PVar:playerID[SETCAMERA_COUNT] = count;
}