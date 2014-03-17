CheckpointEvent(playerID, checkpointID, event)
{
	if (checkpointID >= MAX_CHECKPOINTS)
	{
		printf("  Checkpoint ID (%d) is out of bounds of array (%d)!", checkpointID, MAX_CHECKPOINTS);
		return;
	}

	switch (g_checkpoints[checkpointID][E_CHECKPOINT_TYPE])
	{
		case CHECKPOINTTYPE_GARAGE:
		{
			switch (event)
			{
				case CHECKPOINTEVENT_ENTER:
				{
					SendClientMessageEx(playerID, COLOR_INFO, StringID:145("Press %s to enter the garage"), GetGameTextKeyByID(KEY_CHECKPOINT_USE, IsPlayerInAnyVehicle(playerID)));
				}
				case CHECKPOINTEVENT_KEY:
				{
					new garageNumber = g_checkpoints[checkpointID][E_CHECKPOINT_LINKID];

					if (IsPlayerInAnyVehicle(playerID))
					{
						if (GetPlayerVehicleSeat(playerID) == 0)
						{
							EnterGarage(playerID, garageNumber);
						}
						else
						{
							SendClientMessageEx(playerID, COLOR_ERROR, StringID:19("You are not the driver of this vehicle!"));
						}
					}
					else
					{
						EnterGarage(playerID, garageNumber);
					}
				}
			}
		}
	}
}