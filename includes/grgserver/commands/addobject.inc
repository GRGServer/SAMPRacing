PCMD:addobject[ISADMIN](playerID, params[], StringID:93("Add a new object"))
{
    if (!StrNotNull(PVar:playerID[OBJEDITOR_FILENAME]))
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:109("No filename specified!"));
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:110("Set one using /setobjectfilename"));
        return COMMAND_ERROR;
    }

    new modelID;
    if (sscanf(params, "d", modelID))
    {
        new name[STRINGLENGTH_OBJECTMODELNAME];
        if (sscanf(params, "s[" #STRINGLENGTH_OBJECTMODELNAME "]", name))
        {
            CmdUsageMsg(playerID, "addobject", "ModelID/Name");
            return COMMAND_USAGE;
        }

        new foundObjectsIndex = 0;
        new foundObjects[50];
        Foreach(index, g_objectModels)
        {
            if (foundObjectsIndex >= 50)
            {
                break;
            }

            if (strfind(g_objectModels[index][E_OBJECTMODEL_NAME], name) != -1)
            {
                foundObjects[foundObjectsIndex] = index;
                foundObjectsIndex++;
            }
        }

        if (foundObjectsIndex)
        {
            if (foundObjectsIndex == 1)
            {
                modelID = g_objectModels[foundObjects[foundObjectsIndex]][E_OBJECTMODEL_ID];
            }
            else
            {
                ShowDialog:AddObject(playerID, foundObjects, foundObjectsIndex);
                return COMMAND_OK;
            }
        }
        else
        {
            SendClientMessageEx(playerID, COLOR_ERROR, StringID:94("Object model '%s' not found!"), name);
            return COMMAND_ERROR;
        }
    }

    if (modelID <= 0)
    {
        SendClientMessageEx(playerID, COLOR_ERROR, StringID:95("The model ID must be greater than 0!"));
        return COMMAND_ERROR;
    }

    if (!AddObject(playerID, modelID))
    {
        return COMMAND_ERROR;
    }

    return COMMAND_OK;
}