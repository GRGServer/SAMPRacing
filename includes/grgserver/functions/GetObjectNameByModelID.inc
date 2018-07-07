GetObjectNameByModelID(modelID)
{
    new name[STRINGLENGTH_OBJECTMODELNAME];

    Foreach(index, g_objectModels)
    {
        if (g_objectModels[index][E_OBJECTMODEL_ID] == modelID)
        {
            strcat(name, g_objectModels[index][E_OBJECTMODEL_NAME]);
            break;
        }
    }

    return name;
}