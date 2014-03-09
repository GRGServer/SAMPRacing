ReloadObjects()
{
	print("Loading objects...");

	Foreach(index, g_objects)
	{
		if (IsValidDynamicObject(index + 1))
		{
			DestroyDynamicObject(index + 1);
		}

		Foreach(field, g_objects[])
		{
			g_objects[index][E_OBJECT:field] = 0;
		}
	}

	new item[100];
	new type;
	new totalCount;
	new dir:dirHandle = dir_open("scriptfiles/objects");
	while (dir_list(dirHandle, item, type))
	{
		if (type == FM_FILE)
		{
			printf("  Loading objects from '%s'...", item);

			new filename[STRINGLENGTH_OBJECTFILENAME];
			strmid(filename, item, 0, strlen(item) - 4);
			new count = LoadObjectsFromFile(filename);

			printf("    %d objects loaded", count);

			totalCount += count;
		}
	}

	printf("  %d objects loaded", totalCount);

	UpdateObjectsForAllPlayers();
}