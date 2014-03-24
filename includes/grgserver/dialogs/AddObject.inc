ShowDialog:AddObject(playerID, objects[], objectsSize)
{
	new list[2048];
	Count(index, objectsSize)
	{
		new objectIndex = objects[index];
		FormatNew:line[50]("%d\t%s", g_objectModels[objectIndex][E_OBJECTMODEL_ID], g_objectModels[objectIndex][E_OBJECTMODEL_NAME]);
		ConcatString(list, line, "\n");
	}
	CreateDialog(playerID, "AddObject", DIALOG_STYLE_LIST, LanguageString(playerID, StringID:93("Add a new object")), list, LanguageString(playerID, StringID:99("Add")), LanguageString(playerID, StringID:4("Cancel")));
}

DialogResponse:AddObject(playerID, response, listItem, inputText[])
{
	if (response)
	{
		new modelID;
		new name[STRINGLENGTH_OBJECTMODELNAME];
		if (!sscanf(inputText, "p<\t>ds[" #STRINGLENGTH_OBJECTMODELNAME "]", modelID, name))
		{
			AddObject(playerID, modelID);
		}
	}
}