ShowDialog:ConfirmGarageBuy(playerID)
{
	new pickupID = GetPlayerPickup(playerID);
	if (pickupID == -1)
	{
		return;
	}

	new garageNumber = g_pickups[pickupID][E_PICKUP_LINKID];

	new typeStringID;
	switch (g_garages[garageNumber][E_GARAGE_TYPE])
	{
		case GARAGE_LARGE:
		{
			typeStringID = StringID:135("Large garage");
		}
		case GARAGE_SMALL:
		{
			typeStringID = StringID:136("Small garage");
		}
	}

	new messageString[256];
	new string[100];
	strcat(messageString, LanguageString(playerID, StringID:137("Are you sure to buy this garage?")));
	strcat(messageString, "\n\n");
	Format:string(LanguageString(playerID, StringID:138("Type: %s")), LanguageString(playerID, typeStringID));
	strcat(messageString, string);
	strcat(messageString, "\n");
	Format:string(LanguageString(playerID, StringID:83("Price: $%d")), g_garages[garageNumber][E_GARAGE_PRICE]);
	strcat(messageString, string);

	CreateDialog(playerID, "ConfirmGarageBuy", DIALOG_STYLE_MSGBOX, LanguageString(playerID, StringID:139("Buy garage")), messageString, LanguageString(playerID, StringID:40("OK")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:ConfirmGarageBuy(playerID, response, listItem, inputText[])
{
	if (!response)
	{
		return;
	}

	new pickupID = GetPlayerPickup(playerID);
	if (pickupID == -1)
	{
		return;
	}

	new garageNumber = g_pickups[pickupID][E_PICKUP_LINKID];
	if (GetPlayerMoney(playerID) < g_garages[garageNumber][E_GARAGE_PRICE])
	{
		GameTextForPlayer(playerID, LanguageString(playerID, StringID:80("You do not have enough money!")), 3000, 3);
	}
	else
	{
		g_garages[garageNumber][E_GARAGE_USERID] = PVar:playerID[USERID];
		UpdateGarage(garageNumber);

		SaveGarage(garageNumber);

		UpdateMapIcons(playerID);

		PlayAudioFileForPlayer(playerID, AUDIOFILE_GARAGEBOUGHT);
		GameTextForPlayer(playerID, LanguageString(playerID, StringID:140("Garage bought")), 5000, 1);
	}
}