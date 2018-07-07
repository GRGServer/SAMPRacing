FindNextVehicleModel(startingModelID, type[], goForward)
{
    new modelID = startingModelID;

    do
    {
        if (goForward)
        {
            modelID++;
        }
        else
        {
            modelID--;
        }

        if (modelID < 400)
        {
            modelID = 611;
        }
        if (modelID > 611)
        {
            modelID = 400;
        }
    }
    while (modelID != startingModelID && strcmp(g_vehicleModels[modelID - 400][E_VEHICLEMODEL_TYPE], type, true));

    return modelID;
}