public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PVar:playerid[OBJEDITOR_ID])
	{
		if (IsKeyPressed(KEY_OBJECTEDITOR_CLONE))
		{
			if (StrNotNull(PVar:playerid[OBJEDITOR_FILENAME]))
			{
				AddObject(playerid, Streamer_GetIntData(STREAMER_TYPE_OBJECT, PVar:playerid[OBJEDITOR_ID], E_STREAMER_MODEL_ID), true);
			}
			else
			{
				SendClientMessageEx(playerid, COLOR_ERROR, StringID:109("No filename specified!"));
				SendClientMessageEx(playerid, COLOR_ERROR, StringID:110("Set one using /setobjectfilename"));
			}

			return false;
		}
		else if (IsKeyPressed(KEY_OBJECTEDITOR_REMOVE))
		{
			new objectID = PVar:playerid[OBJEDITOR_ID];

			CancelEdit(playerid);

			new modelID = Streamer_GetIntData(STREAMER_TYPE_OBJECT, objectID, E_STREAMER_MODEL_ID);
			DestroyDynamicObject(objectID);

			new filename[STRINGLENGTH_OBJECTFILENAME];
			strcat(filename, Object:objectID[FILENAME]);

			// Reset all variables of the object
			Count(field, sizeof(g_objects[]))
			{
				g_objects[objectID - 1][E_OBJECT:field] = 0;
			}

			SaveObjects(filename);

			UpdateObjectEditorInfo(playerid, false);

			UpdateObjectsForAllPlayers();
			SelectObject(playerid);

			SendClientMessageEx(playerid, COLOR_INFO, StringID:113("The object %d (%s) has been removed from file '%s'"), modelID, GetObjectNameByModelID(modelID), filename);

			PVar:playerid[OBJEDITOR_ID] = 0;

			return false;
		}
		else if (IsKeyPressed(KEY_OBJECTEDITOR_SETMOVEPOS))
		{
			new objectID = PVar:playerid[OBJEDITOR_ID];

			GetDynamicObjectPos(objectID, Object:objectID[MOVE_POSX], Object:objectID[MOVE_POSY], Object:objectID[MOVE_POSZ]);
			GetDynamicObjectRot(objectID, Object:objectID[MOVE_ROTX], Object:objectID[MOVE_ROTY], Object:objectID[MOVE_ROTZ]);

			SaveObjects(Object:objectID[FILENAME]);

			SendClientMessageEx(playerid, COLOR_INFO, StringID:210("The target move position of the selected object has been saved"));
			SendClientMessageEx(playerid, COLOR_INFO, StringID:211("Use /previewobjectmove to preview the movement"));

			return false;
		}
	}

	if (PVar:playerid[RECNPC_RUNNING])
	{
		if (IsKeyPressed(KEY_RECNPC_STOP))
		{
			PVar:playerid[RECNPC_RUNNING] = false;

			StopRecordingPlayerData(playerid);

			Count(playNPCIndex, MAX_RECNPC_PLAYNPCS)
			{
				new npcID = PVar:playerid[RECNPC_PLAYNPCS][playNPCIndex];
				if (npcID != -1)
				{
					FormatNew:name[MAX_PLAYER_NAME]("NPC_%d", npcID);
					new npcPlayerID = GetPlayerID(name);
					if (npcPlayerID != INVALID_PLAYER_ID)
					{
						SendNPCCommand(npcPlayerID, NPCCMD_STOP);
						SetPlayerVirtualWorld(npcPlayerID, VIRTUALWORLD_IDLENPC);
					}
				}
			}

			new npcID = PVar:playerid[RECNPC_NPCID];
			new vehicleID = GetPlayerVehicleID(playerid);
			if (!vehicleID)
			{
				vehicleID = INVALID_VEHICLE_ID;
			}

			// Find a free ID for the new recording
			new highestID = -1;
			Foreach(arrayIndex, g_npcs)
			{
				if (g_npcs[arrayIndex][E_NPC_ID] > highestID)
				{
					highestID = g_npcs[arrayIndex][E_NPC_ID];
				}
			}
			g_npcs[npcID][E_NPC_ID] = highestID + 1;

			strdel(g_npcs[npcID][E_NPC_RECORDING_NAME], 0, STRINGLENGTH_NPCRECORDINGNAME);
			strcat(g_npcs[npcID][E_NPC_RECORDING_NAME], PVar:playerid[RECNPC_NAME], STRINGLENGTH_NPCRECORDINGNAME);

			g_npcs[npcID][E_NPC_RECORDING_TYPE] = PVar:playerid[RECNPC_TYPE];
			g_npcs[npcID][E_NPC_SKIN] = 0;
			g_npcs[npcID][E_NPC_INTERIOR] = GetPlayerInterior(playerid);
			g_npcs[npcID][E_NPC_VEHICLE_ID] = vehicleID;

			if (vehicleID == INVALID_VEHICLE_ID)
			{
				g_npcs[npcID][E_NPC_VEHICLE_MODELID] = 0;
				g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB] = -1;

				Count(componentSlot, MAX_VEHICLECOMPONENT_SLOTS)
				{
					g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot] = 0;
				}
			}
			else
			{
				g_npcs[npcID][E_NPC_VEHICLE_MODELID] = GetVehicleModel(vehicleID);
				g_npcs[npcID][E_NPC_VEHICLE_PAINTJOB] = VehicleProperty:vehicleID[PAINTJOBID];

				Count(componentSlot, MAX_VEHICLECOMPONENT_SLOTS)
				{
					g_npcs[npcID][E_NPC_VEHICLE_COMPONENTS][componentSlot] = GetVehicleComponentInSlot(vehicleID, componentSlot);
				}
			}

			// Move the recording to npcmodes/recordings
			FormatNew:sourceFilename[100]("scriptfiles/%s.rec", PVar:playerid[RECNPC_NAME]);
			FormatNew:destinationFilename[100]("npcmodes/recordings/%s.rec", PVar:playerid[RECNPC_NAME]);
			file_move(sourceFilename, destinationFilename);

			SaveNPCs();

			SendClientMessageEx(playerid, COLOR_INFO, StringID:184("The NPC recording '%s' has been stopped"), PVar:playerid[RECNPC_NAME]);

			return false;
		}
	}

	if (IsKeyPressed(KEY_PICKUP_USE))
	{
		new pickupID = GetPlayerPickup(playerid);
		if (pickupID != -1)
		{
			PickupEvent(playerid, pickupID, PICKUPEVENT_KEY);
			return false;
		}
	}

	if (IsKeyPressed(KEY_CHECKPOINT_USE))
	{
		new checkpointID = GetPlayerVisibleDynamicCP(playerid);
		if (IsValidDynamicCP(checkpointID))
		{
			new Float:posX;
			new Float:posY;
			new Float:posZ;
			new Float:size;

			Streamer_GetFloatData(STREAMER_TYPE_CP, checkpointID, E_STREAMER_X, posX);
			Streamer_GetFloatData(STREAMER_TYPE_CP, checkpointID, E_STREAMER_Y, posY);
			Streamer_GetFloatData(STREAMER_TYPE_CP, checkpointID, E_STREAMER_Z, posZ);
			Streamer_GetFloatData(STREAMER_TYPE_CP, checkpointID, E_STREAMER_SIZE, size);

			if (IsPlayerInRangeOfPoint(playerid, size, posX, posY, posZ))
			{
				CheckpointEvent(playerid, checkpointID, CHECKPOINTEVENT_KEY);
				return false;
			}
		}
	}

	if (PVar:playerid[GARAGE_NUMBER] != -1)
	{
		if (IsKeyPressed(KEY_GARAGE_PREVIOUS))
		{
			cache_set_active(PVar:playerid[GARAGE_MYSQLCACHEID]);
			new row = PVar:playerid[GARAGE_ROW];
			if (row)
			{
				row--;
			}
			else
			{
				row = cache_get_row_count() - 1;
			}
			CreateGarageVehicle(playerid, row);
			return false;
		}
		else if (IsKeyPressed(KEY_GARAGE_NEXT))
		{
			cache_set_active(PVar:playerid[GARAGE_MYSQLCACHEID]);
			new row = PVar:playerid[GARAGE_ROW];
			if (row < cache_get_row_count() - 1)
			{
				row++;
			}
			else
			{
				row = 0;
			}
			CreateGarageVehicle(playerid, row);
			return false;
		}
		else if (IsKeyPressed(KEY_GARAGE_GET))
		{
			ExitGarage(playerid, true);
			return false;
		}
		else if (IsKeyPressed(KEY_GARAGE_QUIT))
		{
			ExitGarage(playerid, false);
			return false;
		}
	}

	if (PVar:playerid[VEHICLESHOP_ID] != -1)
	{
		if (IsKeyPressed(KEY_VEHICLESHOP_PREVIOUS))
		{
			PVar:playerid[VEHICLESHOP_MODELID] = FindNextVehicleModel(PVar:playerid[VEHICLESHOP_MODELID], "Car", false);
			CreateVehicleShopVehicle(playerid);
			return false;
		}
		else if (IsKeyPressed(KEY_VEHICLESHOP_NEXT))
		{
			PVar:playerid[VEHICLESHOP_MODELID] = FindNextVehicleModel(PVar:playerid[VEHICLESHOP_MODELID], "Car", true);
			CreateVehicleShopVehicle(playerid);
			return false;
		}
		else if (IsKeyPressed(KEY_VEHICLESHOP_BUY))
		{
			new price = g_vehicleModels[PVar:playerid[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE];
			if (GetPlayerMoney(playerid) < price)
			{
				GameTextForPlayer(playerid, LanguageString(playerid, StringID:80("You do not have enough money!")), 3000, 3);
			}
			else
			{
				ShowDialog:ConfirmVehicleBuy(playerid);
			}
			return false;
		}
		else if (IsKeyPressed(KEY_VEHICLESHOP_QUIT))
		{
			ExitVehicleShop(playerid, false);
			return false;
		}
	}

	return true;
}