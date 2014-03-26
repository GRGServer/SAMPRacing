ResetPlayerVariables(playerID)
{
	Foreach(playerVariable, g_playerVariables[])
	{
		g_playerVariables[playerID][E_PVAR:playerVariable] = 0;
	}

	// Initialize variables with default values
	PVar:playerID[GARAGE_NUMBER] = -1;
	PVar:playerID[GARAGE_VEHICLE_ID] = INVALID_VEHICLE_ID;
	PVar:playerID[NPCID] = -1;
	PVar:playerID[RACE_ID] = -1;
	PVar:playerID[VEHICLESHOP_ID] = -1;
	PVar:playerID[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;

	Count(playNPCIndex, MAX_RECNPC_PLAYNPCS)
	{
		PVar:playerID[RECNPC_PLAYNPCS][playNPCIndex] = -1;
	}
}