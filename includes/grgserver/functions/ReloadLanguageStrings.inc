ReloadLanguageStrings()
{
	print("Loading language strings...");

	Foreach(index, g_languageStrings)
	{
		Foreach(field, g_languageStrings[])
		{
			g_languageStrings[index][E_LANGUAGESTRING:field] = 0;
		}
	}

	new count;
	new highestStringID;
	new XMLNode:xml = XML_LoadDocument("languagestrings.xml");
	xml = XML_GetFirstChild(xml, "languagestrings");
	new XMLNode:stringNode = XML_GetFirstChild(xml, "string");
	while (stringNode)
	{
		new value[256];
		new stringIDstr[16];
		XML_GetAttribute(stringNode, "id", stringIDstr);
		new stringID = strval(stringIDstr);
		if (stringID < MAX_LANGUAGE_STRINGS)
		{
			new XMLNode:translationNode;
			translationNode = XML_GetFirstChild(stringNode, "en");
			if (translationNode)
			{
				new XMLNode:textNode = XML_GetFirstChild(translationNode);
				if (textNode)
				{
					XML_GetValue(textNode, value);
					value = str_replace("\\n", "\n", value);
					value = str_replace("\\t", "\t", value);
					strcat(g_languageStrings[stringID][E_LANGUAGESTRING_ENGLISH], value, STRINGLENGTH_LANGUAGESTRING);
				}
				else
				{
					printf("  Missing English language string for string %d", stringID);
				}
			}
			else
			{
				printf("  Missing English language string for string %d", stringID);
			}
			translationNode = XML_GetFirstChild(stringNode, "de");
			if (translationNode)
			{
				new XMLNode:textNode = XML_GetFirstChild(translationNode);
				if (textNode)
				{
					XML_GetValue(textNode, value);
					value = str_replace("\\n", "\n", value);
					value = str_replace("\\t", "\t", value);
					strcat(g_languageStrings[stringID][E_LANGUAGESTRING_GERMAN], value, STRINGLENGTH_LANGUAGESTRING);
				}
				else
				{
					printf("  Missing German language string for string %d", stringID);
				}
			}
			else
			{
				printf("  Missing German language string for string %d", stringID);
			}
			if (stringID > highestStringID)
			{
				highestStringID = stringID;
			}
			count++;
		}
		else
		{
			printf("  Language string ID %d is greater than language array size (%d)", stringID, MAX_LANGUAGE_STRINGS);
			break;
		}
		stringNode = XML_GetNextSibling(stringNode, "string");
	}
	XML_UnloadDocument(xml);

	Count(stringID, highestStringID + 1)
	{
		if (!strlen(g_languageStrings[stringID][E_LANGUAGESTRING_ENGLISH]) && !strlen(g_languageStrings[stringID][E_LANGUAGESTRING_GERMAN]))
		{
			printf("  Unused language string ID %d", stringID);
		}
	}

	printf("  %d language strings loaded", count);
}