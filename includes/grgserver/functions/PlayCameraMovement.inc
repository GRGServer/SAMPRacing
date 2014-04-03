PlayCameraMovement(playerID, movementIndex, delayTimer = 0)
{
	new Float:startPosX = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSX];
	new Float:startPosY = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSY];
	new Float:startPosZ = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSZ];

	new Float:endPosX = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSX];
	new Float:endPosY = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSY];
	new Float:endPosZ = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSZ];

	new Float:startLookAtX = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATX];
	new Float:startLookAtY = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATY];
	new Float:startLookAtZ = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATZ];

	new Float:endLookAtX = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATX];
	new Float:endLookAtY = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATY];
	new Float:endLookAtZ = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATZ];

	new time = g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_TIME];

	InterpolateCameraPos(playerID, startPosX, startPosY, startPosZ, endPosX, endPosY, endPosZ, time, CAMERA_MOVE);
	InterpolateCameraLookAt(playerID, startLookAtX, startLookAtY, startLookAtZ, endLookAtX, endLookAtY, endLookAtZ, time, CAMERA_MOVE);

	PVar:playerID[CAMERAMOVEMENTTIMER] = SetTimerEx("OnCameraMovementEnded", time + delayTimer, false, "dd", playerID, movementIndex);
}