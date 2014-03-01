ReloadObjectModels()
{
	print("Loading object models...");

	Foreach(index, g_objectModels)
	{
		Foreach(field, g_objectModels[])
		{
			g_objectModels[index][E_OBJECTMODEL:field] = 0;
		}
	}

	new index = 0;
	new line[256];
	new File:file = fopen("objectmodels.dat", io_read);
	while (fread(file, line))
	{
		new modelID;
		new name[STRINGLENGTH_OBJECTMODELNAME];
		if (!sscanf(line, "p<\t>ds[" #STRINGLENGTH_OBJECTMODELNAME "]", modelID, name))
		{
			if (index >= MAX_OBJECTMODELS)
			{
				printf("  Reached limit of %d object models", MAX_OBJECTMODELS);
				break;
			}

			g_objectModels[index][E_OBJECTMODEL_ID] = modelID;
			g_objectModels[index][E_OBJECTMODEL_NAME] = name;
			index++;
		}
	}
	fclose(file);

	printf("  %d object models loaded", index);
}