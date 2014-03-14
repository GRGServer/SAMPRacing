CMD:unlock(playerID, params[], StringID:148("Unlock your Vehicle!"))
{
	new Float:X;
	new Float:Y;
	new Float:Z;
	
	if(IsPlayerConnected(playerID) && VehicleStatus[GetPlayerVehicleID(playerID)] == 1)
	{
		new VehicleState = GetPlayerState(playerID);
		if(VehicleState == PLAYER_STATE_DRIVER)
		{
			for(new v = 0; v <L_VEHICLE; v++)
			{
				SetVehicleParamsForPlayer(GetPlayerVehicleID(playerID),v, 0, 0);
			}
			SendClientMessage(playerID,AQUAGREEN, "***(LuxSpeedo): Vehicle Unlocked!");
			GetPlayerPos(playerID,X,Y,Z);
			PlayerPlaySound(playerID,1057,X,Y,Z); VehicleStatus[GetPlayerVehicleID(playerID)] = 0;
		}
		return true;
  	}
	return COMMAND_OK;
}