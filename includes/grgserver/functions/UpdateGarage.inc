UpdateGarage(garageNumber)
{
	if (IsValidDynamicCP(g_garages[garageNumber][E_GARAGE_CHECKPOINT_ID]))
	{
		DestroyDynamicCP(g_garages[garageNumber][E_GARAGE_CHECKPOINT_ID]);
		g_garages[garageNumber][E_GARAGE_CHECKPOINT_ID] = 0;
	}

	if (g_garages[garageNumber][E_GARAGE_PICKUP_ID] != -1)
	{
		DestroyPickup(g_garages[garageNumber][E_GARAGE_PICKUP_ID]);
	}

	new pickupType;
	if (g_garages[garageNumber][E_GARAGE_USERID])
	{
		pickupType = PICKUPTYPE_GARAGE_BOUGHT;
		new playerID = GetPlayerIDByUserID(g_garages[garageNumber][E_GARAGE_USERID]);
		if (playerID != INVALID_PLAYER_ID)
		{
			new checkpointID = CreateDynamicCP(g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSX], g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSY], g_garages[garageNumber][E_GARAGE_CHECKPOINT_POSZ], 4, 0, 0, playerID);

			g_checkpoints[checkpointID][E_CHECKPOINT_TYPE] = CHECKPOINTTYPE_GARAGE;
			g_checkpoints[checkpointID][E_CHECKPOINT_LINKID] = garageNumber;

			g_garages[garageNumber][E_GARAGE_CHECKPOINT_ID] = checkpointID;
		}
	}
	else
	{
		pickupType = PICKUPTYPE_GARAGE_FREE;
	}

	g_garages[garageNumber][E_GARAGE_PICKUP_ID] = AddPickup(pickupType, g_garages[garageNumber][E_GARAGE_PICKUP_POSX], g_garages[garageNumber][E_GARAGE_PICKUP_POSY], g_garages[garageNumber][E_GARAGE_PICKUP_POSZ], garageNumber);
}