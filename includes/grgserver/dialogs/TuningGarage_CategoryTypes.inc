ShowDialog:TuningGarage_CategoryTypes(playerID, category)
{
    new list[2048];

    switch (category)
    {
        case 0:// Front bumber
        {
        }
        case 1:// Read bumber
        {
        }
        case 2:// Spoiler
        {
        }
        case 3:// Neon
        {
        }
        // 4 = Numberplate which is handled in another dialog
        case 5:// Lights
        {
        }
        case 6:// Roof
        {
        }
        case 7:// Hood
        {
        }
    }

    CreateDialog(playerID, "TuningGarage_CategoryTypes", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:223("Select an item")), list, LanguageString(playerID, StringID:224("Buy")), LanguageString(playerID, StringID:34("Back")));
}

DialogResponse:TuningGarage_CategoryTypes(playerID, response, listItem, inputText[])
{
    if (response)
    {

    }
    else
    {
        ShowDialog:TuningGarage_MainMenu(playerID);
    }
}