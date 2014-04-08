ShowDialog:TuningGarage_NP_City(playerID)
{
	new list[200];

	strcat(list, "Los Santos\n");// 0
	strcat(list, "Las Venturas\n");// 1
	strcat(list, "San Fierro");// 2

	CreateDialog(playerID, "TuningGarage_NP_City", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:225("Select a city")), list, LanguageString(playerID, StringID:37("Next")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:TuningGarage_NP_City(playerID, response, listItem, inputText[])
{
	if (response)
	{
		ShowDialog:TuningGarage_NP_NumberInput(playerID, listItem);
	}
	else
	{
		ShowDialog:TuningGarage_MainMenu(playerID);
	}
}