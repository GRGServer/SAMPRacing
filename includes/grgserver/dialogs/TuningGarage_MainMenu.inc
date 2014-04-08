ShowDialog:TuningGarage_MainMenu(playerID)
{
	new list[1024];

	ConcatString(list, LanguageString(playerID, StringID:226("Front bumber")), "\n");// 0
	ConcatString(list, LanguageString(playerID, StringID:227("Rear bumber")), "\n");// 1
	ConcatString(list, LanguageString(playerID, StringID:228("Spoiler")), "\n");// 2
	ConcatString(list, LanguageString(playerID, StringID:229("Neon")), "\n");// 3
	ConcatString(list, LanguageString(playerID, StringID:230("Numberplate")), "\n");// 4
	ConcatString(list, LanguageString(playerID, StringID:231("Lights")), "\n");// 5
	ConcatString(list, LanguageString(playerID, StringID:232("Roof")), "\n");// 6
	ConcatString(list, LanguageString(playerID, StringID:233("Hood")), "\n");// 7

	CreateDialog(playerID, "TuningGarage_MainMenu", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:234("Select a category")), list, LanguageString(playerID, StringID:37("Next")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:TuningGarage_MainMenu(playerID, response, listItem, inputText[])
{
	if (response)
	{
		if (listItem == 4)// Numberplate
		{
			ShowDialog:TuningGarage_NP_City(playerID);
		}
		else
		{
			ShowDialog:TuningGarage_CategoryTypes(playerID, listItem);
		}
	}
}