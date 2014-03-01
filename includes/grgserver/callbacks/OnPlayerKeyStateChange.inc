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

			UpdateObjectsForAllPlayers();
			SelectObject(playerid);

			SendClientMessageEx(playerid, COLOR_INFO, StringID:113("The object %d (%s) has been removed from file '%s'"), modelID, GetObjectNameByModelID(modelID), filename);

			PVar:playerid[OBJEDITOR_ID] = 0;

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