public OnPlayerDisconnect(playerid, reason)
{
	if (IsPlayerNPC(playerid))
	{
		new prefix[MAX_PLAYER_NAME];
		new npcID;
		sscanf(GetPlayerNameEx(playerid), "p<_>s[10]d", prefix, npcID);

		if (npcID >=0 && npcID < MAX_NPCS)
		{
			if (g_npcs[npcID][E_NPC_VEHICLE_ID] != INVALID_VEHICLE_ID)
			{
				DestroyVehicleEx(g_npcs[npcID][E_NPC_VEHICLE_ID]);
			}
		}

		ResetPlayerVariables(playerid);

		return true;
	}

	SavePlayer(playerid);

	SendDeathMessage(INVALID_PLAYER_ID, playerid, ICON_DISCONNECT);

	new reasonString[16];
	switch (reason)
	{
		case 0:
		{
			strcat(reasonString, "Timed out");
		}
		case 1:
		{
			strcat(reasonString, "Leaving");
		}
		case 2:
		{
			strcat(reasonString, "Kicked/Banned");
		}
	}

	// Send leave message to all players except the leaving player
	PlayerLoop(playerID)
	{
		if (!IsPlayerNPC(playerID) && playerID != playerid)
		{
			SendClientMessageEx(playerID, COLOR_JOINLEAVE, StringID:22("%u has left the server (%s)"), playerid, reasonString);
		}
	}

	// Is player in race?
	new raceID = PVar:playerid[RACE_ID];
	if (raceID != -1)
	{
		g_races[raceID][E_RACE_HOSTPLAYERID] = INVALID_PLAYER_ID;

		// Search for another host of the race
		PlayerLoop(playerID)
		{
			if (playerID != playerid && PVar:playerID[RACE_ID] == raceID && PVar:playerID[RACE_LOBBYUPDATETIMER])
			{
				g_races[raceID][E_RACE_HOSTPLAYERID] = playerID;

				FormatNew:string[100]("~n~~n~~n~~n~~n~~n~~n~~n~~n~%s", LanguageString(playerID, StringID:185("You are now the host of this race")));
				GameTextForPlayer(playerID, string, 3000, 3);

				PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_RACELOBBY_BUTTON_START]);
				break;
			}
		}

		EndRace(playerid);
	}

	ResetPlayerVariables(playerid);

	return true;
}