ShowDialog:TuningGarage_NP_NumberInput(playerID, city)
{
	PVar:playerID[TUNINGGARAGE_NP_CITY] = city;

	CreateDialog(playerID, "TuningGarage_NP_NumberInput", DIALOG_STYLE_INPUT, LanguageString(playerID, StringID:235("Set number plate text")), LanguageString(playerID, StringID:236("Enter up to 4 characters you want to have as your number plate")), LanguageString(playerID, StringID:224("Buy")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:TuningGarage_NP_NumberInput(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (strlen(inputText) < 1 || strlen(inputText) > 4)
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:238("The number plate text should have between 1 and 4 characters!"));
			ShowDialog:TuningGarage_NP_NumberInput(playerID, PVar:playerID[TUNINGGARAGE_NP_CITY]);
		}
		else
		{
			if (GetPlayerMoney(playerID) < TUNINGGARAGE_PRICE_NUMBERPLATE)
			{
				GameTextForPlayer(playerID, LanguageString(playerID, StringID:80("You do not have enough money!")), 3000, 3);
				ShowDialog:TuningGarage_NP_NumberInput(playerID, PVar:playerID[TUNINGGARAGE_NP_CITY]);
			}
			else
			{
				new city[3];

				switch (PVar:playerID[TUNINGGARAGE_NP_CITY])
				{
					case 0:// Los Santos
					{
						city = "LS";
					}
					case 1:// Las Venturas
					{
						city = "LV";
					}
					case 2:// San Fierro
					{
						city = "SF";
					}
				}

				FormatNew:numberPlateText[STRINGLENGTH_NUMBERPLATE]("%s-%s", city, inputText);
				SetVehicleNumberPlateEx(PVar:playerID[TUNINGGARAGE_VEHICLEID], numberPlateText);

				GivePlayerMoney(playerID, -TUNINGGARAGE_PRICE_NUMBERPLATE);

				ShowDialog:TuningGarage_MainMenu(playerID);
			}
		}
	}
	else
	{
		ShowDialog:TuningGarage_NP_City(playerID);
	}
}