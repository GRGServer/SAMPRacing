EnterTuningGarage(playerID, tuningGarageNumber)
{
	PVar:playerID[ALLOWCMDS] = false;

	PVar:playerID[TUNINGGARAGE_NUMBER] = tuningGarageNumber;

	new vehicleID = GetPlayerVehicleID(playerID);

	SetPlayerVirtualWorld(playerID, VIRTUALWORLD_TUNINGGARAGE + playerID);
	SetVehicleVirtualWorld(vehicleID, VIRTUALWORLD_TUNINGGARAGE + playerID);

	TogglePlayerSpectating(playerID, true);

	SetPlayerCameraPosEx(playerID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_CAMERA_POSZ], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ]);

	// Fix vehicle position and angle
	SetVehiclePos(vehicleID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSX], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSY], g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_POSZ]);
	SetVehicleZAngle(vehicleID, g_tuningGarages[tuningGarageNumber][E_TUNINGGARAGE_VEHICLE_ANGLE]);

	ShowDialog:TuningGarage_MainMenu(playerID);
}