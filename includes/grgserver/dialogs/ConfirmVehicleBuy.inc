ShowDialog:ConfirmVehicleBuy(playerID)
{
    new vehicleModelIndex = PVar:playerID[VEHICLESHOP_MODELID] - 400;

    new messageString[256];
    new string[100];
    strcat(messageString, LanguageString(playerID, StringID:81("Are you sure to buy the vehicle?")));
    strcat(messageString, "\n\n");
    Format:string(LanguageString(playerID, StringID:82("Name: %s")), g_vehicleModels[vehicleModelIndex][E_VEHICLEMODEL_NAME]);
    strcat(messageString, string);
    strcat(messageString, "\n");
    Format:string(LanguageString(playerID, StringID:83("Price: $%d")), g_vehicleModels[vehicleModelIndex][E_VEHICLEMODEL_PRICE]);
    strcat(messageString, string);

    CreateDialog(playerID, "ConfirmVehicleBuy", DIALOG_STYLE_MSGBOX, LanguageString(playerID, StringID:84("Buy vehicle")), messageString, LanguageString(playerID, StringID:40("OK")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:ConfirmVehicleBuy(playerID, response, listItem, inputText[])
{
    if (response)
    {
        if (GetPlayerMoney(playerID) < g_vehicleModels[PVar:playerID[VEHICLESHOP_MODELID] - 400][E_VEHICLEMODEL_PRICE])
        {
            GameTextForPlayer(playerID, LanguageString(playerID, StringID:80("You do not have enough money!")), 3000, 3);
        }
        else
        {
            ExitVehicleShop(playerID, true);
        }
    }
}