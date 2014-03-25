ReloadCommandAliases()
{
	print("Loading command aliases...");

	Foreach(index, g_commandAliases)
	{
		Foreach(field, g_commandAliases[])
		{
			g_commandAliases[index][E_COMMANDALIAS:field] = 0;
		}
	}

	new aliasID = 0;
	new XMLNode:xml = XML_LoadDocument("commandaliases.xml");
	xml = XML_GetFirstChild(xml, "commandaliases");
	new XMLNode:aliasNode = XML_GetFirstChild(xml, "alias");
	while (aliasNode)
	{
		new XMLNode:node;

		if (aliasID >= MAX_TELEPORTS)
		{
			printf("  Reached limit of %d command aliases", MAX_COMMANDALIASES);
			break;
		}

		// Read "name" value
		node = XML_GetFirstChild(aliasNode, "name");
		if (node)
		{
			XML_GetValue(XML_GetFirstChild(node), g_commandAliases[aliasID][E_COMMANDALIAS_NAME], STRINGLENGTH_COMMANDNAME);
		}
		else
		{
			printf("  Node 'name' missing for command alias %d", aliasID);
			aliasNode = XML_GetNextSibling(aliasNode, "alias");
			continue;
		}

		// Read "command" value
		node = XML_GetFirstChild(aliasNode, "command");
		if (node)
		{
			XML_GetValue(XML_GetFirstChild(node), g_commandAliases[aliasID][E_COMMANDALIAS_COMMAND], STRINGLENGTH_COMMANDNAME);
		}
		else
		{
			printf("  Node 'command' missing for command alias %d", aliasID);
			aliasNode = XML_GetNextSibling(aliasNode, "alias");
			continue;
		}

		// Read "parameters" value
		node = XML_GetFirstChild(aliasNode, "parameters");
		if (node)
		{
			XML_GetValue(XML_GetFirstChild(node), g_commandAliases[aliasID][E_COMMANDALIAS_PARAMETERS], STRINGLENGTH_CMDALIASPARAMS);
		}
		else
		{
			g_commandAliases[aliasID][E_COMMANDALIAS_PARAMETERS] = 0;
		}

		aliasID++;

		aliasNode = XML_GetNextSibling(aliasNode, "alias");
	}
	XML_UnloadDocument(xml);

	printf("  %d command aliases loaded", aliasID);
}