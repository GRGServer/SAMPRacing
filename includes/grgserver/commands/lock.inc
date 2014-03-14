CMD:lock(playerID, params[], StringID:147("Lock your Vehicle!"))
{
	new Float:X;
	new Float:Y;
	new Float:Z;
	
	if(IsPlayerConnected(playerID) && VehicleStatus[GetPlayerVehicleID(playerID)] == 0)
	{
		new VehicleState = GetPlayerState(playerID);
		
		if(VehicleState == PLAYER_STATE_DRIVER)
		{
			for(new v = 0; v <L_VEHICLE; v++)
			{
				if (v != playerID)
				{
					SetVehicleParamsForPlayer(GetPlayerVehicleID(playerID),v, 0, 1);
				}
			}
			SendClientMessage(playerID,AQUAGREEN, "***(LuxSpeedo): Vehicle Locked!");
			GetPlayerPos(playerID,X,Y,Z);
			PlayerPlaySound(playerID,1057,X,Y,Z);
			VehicleStatus[GetPlayerVehicleID(playerID)] = 1;
			SetTimerEx("LAutoUnlock",VehLockTime*60000,false,"i",GetPlayerVehicleID(playerID));
		}
		return true;
	}
	return COMMAND_OK;
}
