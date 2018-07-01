public OnPlayerSpawn(playerid)
{
	if (IsPlayerNPC(playerid))
	{
		SetPlayerVirtualWorld(playerid, VIRTUALWORLD_IDLENPC);

		new npcID = PVar:playerid[NPCID];

		SetPlayerInterior(playerid, g_npcs[npcID][E_NPC_INTERIOR]);

		if (g_npcs[npcID][E_NPC_VEHICLE_ID] != INVALID_VEHICLE_ID && g_npcs[npcID][E_NPC_RECORDING_TYPE] == PLAYER_RECORDING_TYPE_DRIVER)
		{
			SetVehicleVirtualWorld(g_npcs[npcID][E_NPC_VEHICLE_ID], VIRTUALWORLD_IDLENPC);
			LinkVehicleToInterior(g_npcs[npcID][E_NPC_VEHICLE_ID], g_npcs[npcID][E_NPC_INTERIOR]);

			PutPlayerInVehicle(playerid, g_npcs[npcID][E_NPC_VEHICLE_ID], 0);
			SetVehicleEngineState(g_npcs[npcID][E_NPC_VEHICLE_ID], true);
		}

		if (g_npcs[npcID][E_NPC_ID] == RACE_LOBBY_NPC1 || g_npcs[npcID][E_NPC_ID] == RACE_LOBBY_NPC2)
		{
			// Change the virtual world to the lobby world
			SetPlayerVirtualWorld(playerid, VIRTUALWORLD_RACELOBBY);
			SetVehicleVirtualWorld(g_npcs[npcID][E_NPC_VEHICLE_ID], VIRTUALWORLD_RACELOBBY);
			PutPlayerInVehicle(playerid, g_npcs[npcID][E_NPC_VEHICLE_ID], 0);

			SendNPCCommand(playerid, #NPCCMD_SETREPEAT " 1");
			SendNPCCommand(playerid, #NPCCMD_START " 1000");
		}

		return true;
	}

	switch (PVar:playerid[SPAWN_TYPE])
	{
		case SPAWNTYPE_BUYVEHICLESHOP:// Spawned after buying a vehicle from vehicle shop
		{
			new vehicleID = PVar:playerid[VEHICLESHOP_VEHICLEID];

			VehicleProperty:vehicleID[USERID] = PVar:playerid[USERID];

			SetPlayerInterior(playerid, PVar:playerid[SPAWN_INTERIOR]);

			SetVehiclePos(vehicleID, PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);
			SetVehicleZAngle(vehicleID, PVar:playerid[SPAWN_ANGLE]);

			LinkVehicleToInterior(vehicleID, PVar:playerid[SPAWN_INTERIOR]);
			SetVehicleVirtualWorld(vehicleID, 0);
			PutPlayerInVehicle(playerid, vehicleID, 0);

			SetCameraBehindPlayer(playerid);

			SaveVehicle(vehicleID, true);

			GivePlayerMoney(playerid, -g_vehicleModels[PVar:playerid[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE]);

			PlayAudioFileForPlayer(playerid, AUDIOFILE_VEHICLEBOUGHT);
			GameTextForPlayer(playerid, LanguageString(playerid, StringID:85("Vehicle bought")), 5000, 1);

			PVar:playerid[VEHICLESHOP_ID] = -1;
			PVar:playerid[VEHICLESHOP_VEHICLEID] = INVALID_VEHICLE_ID;
		}
		case SPAWNTYPE_EXITGARAGE:
		{
			new vehicleID = PVar:playerid[GARAGE_VEHICLE_ID];

			SetPlayerInterior(playerid, PVar:playerid[SPAWN_INTERIOR]);

			if (vehicleID == INVALID_VEHICLE_ID)
			{
				SetPlayerPos(playerid, PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);
				SetPlayerFacingAngle(playerid, PVar:playerid[SPAWN_ANGLE]);
			}
			else
			{
				SetVehiclePos(vehicleID, PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);
				SetVehicleZAngle(vehicleID, PVar:playerid[SPAWN_ANGLE]);

				LinkVehicleToInterior(vehicleID, PVar:playerid[SPAWN_INTERIOR]);
				SetVehicleVirtualWorld(vehicleID, 0);
				PutPlayerInVehicle(playerid, vehicleID, 0);

				VehicleProperty:vehicleID[GARAGEID] = 0;

				MySQLFormat("UPDATE `vehicles` SET `garageId` = NULL WHERE `id` = %d", VehicleProperty:vehicleID[SAVEID]);
				mysql_pquery(g_mysql, g_sqlQuery);

				SaveVehicle(vehicleID, true);
			}

			SetCameraBehindPlayer(playerid);

			PVar:playerid[GARAGE_NUMBER] = -1;
			PVar:playerid[GARAGE_VEHICLE_ID] = INVALID_VEHICLE_ID;
		}
		case SPAWNTYPE_EXITTUNINGGARAGE:
		{
			new vehicleID = PVar:playerid[TUNINGGARAGE_VEHICLEID];

			SetPlayerInterior(playerid, PVar:playerid[SPAWN_INTERIOR]);

			SetVehiclePos(vehicleID, PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);
			SetVehicleZAngle(vehicleID, PVar:playerid[SPAWN_ANGLE]);

			LinkVehicleToInterior(vehicleID, PVar:playerid[SPAWN_INTERIOR]);
			SetVehicleVirtualWorld(vehicleID, 0);
			PutPlayerInVehicle(playerid, vehicleID, 0);

			SetCameraBehindPlayer(playerid);

			PVar:playerid[TUNINGGARAGE_NUMBER] = -1;
			PVar:playerid[TUNINGGARAGE_VEHICLEID] = INVALID_VEHICLE_ID;
		}
		case SPAWNTYPE_LEAVERACE:
		{
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);

			SetVehicleVirtualWorld(PVar:playerid[RACE_VEHICLEID], 0);

			PutPlayerInVehicle(playerid, PVar:playerid[RACE_VEHICLEID], 0);

			SetCameraBehindPlayer(playerid);

			FadeInScreen(playerid, 5, SCREENFADER_RACE_LEAVELOBBY);
		}
		case SPAWNTYPE_STARTRACE:
		{
			new raceID = PVar:playerid[RACE_ID];

			SetVehiclePos(PVar:playerid[RACE_VEHICLEID], PVar:playerid[SPAWN_POSX], PVar:playerid[SPAWN_POSY], PVar:playerid[SPAWN_POSZ]);

			SetPlayerInterior(playerid, 0);// TODO: Races in interiors?
			SetPlayerVirtualWorld(playerid, VIRTUALWORLD_RACE + raceID);

			SetVehicleVirtualWorld(PVar:playerid[RACE_VEHICLEID], VIRTUALWORLD_RACE + raceID);

			PutPlayerInVehicle(playerid, PVar:playerid[RACE_VEHICLEID], 0);

			SetVehicleZAngle(PVar:playerid[RACE_VEHICLEID], PVar:playerid[SPAWN_ANGLE]);

			TogglePlayerControllable(playerid, false);

			SetCameraBehindPlayer(playerid);

			PVar:playerid[RACE_STARTED] = true;

			ShowRaceCheckpoint(playerid, raceID, 0);// Show the first checkpoint

			FadeInScreen(playerid, 5, SCREENFADER_RACE_START);
		}
		default:
		{
			new Float:posX = PVar:playerid[SPAWN_POSX];
			new Float:posY = PVar:playerid[SPAWN_POSY];
			new Float:posZ = PVar:playerid[SPAWN_POSZ];
			new Float:angle = PVar:playerid[SPAWN_ANGLE];
			new interior = PVar:playerid[SPAWN_INTERIOR];

			// Specified position of the player is 0 x 0 x 0 which means the spawn location has not been set (e.g. first spawn or unexcpected respawn)
			if (!posX && !posY && !posZ)
			{
				posX = SPAWN_POSX;
				posY = SPAWN_POSY;
				posZ = SPAWN_POSZ;
				angle = SPAWN_ANGLE;
				interior = SPAWN_INTERIOR;
			}

			SetPlayerPos(playerid, posX, posY, posZ);
			SetPlayerFacingAngle(playerid, angle);
			SetPlayerInterior(playerid, interior);

			SetCameraBehindPlayer(playerid);
		}
	}

	// Reset spawn values
	PVar:playerid[SPAWN_TYPE] = SPAWNTYPE_DEFAULT;
	PVar:playerid[SPAWN_POSX] = 0;
	PVar:playerid[SPAWN_POSY] = 0;
	PVar:playerid[SPAWN_POSZ] = 0;
	PVar:playerid[SPAWN_ANGLE] = 0;
	PVar:playerid[SPAWN_INTERIOR] = 0;

	return true;
}