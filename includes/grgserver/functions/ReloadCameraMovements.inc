ReloadCameraMovements()
{
	print("Loading camera movements...");

	Foreach(index, g_cameraMovements)
	{
		Foreach(field, g_cameraMovements[])
		{
			g_cameraMovements[index][E_CAMERAMOVEMENT:field] = 0;
		}
	}

	new movementIndex;
	new XMLNode:xml = XML_LoadDocument("cameramovements.xml");
	xml = XML_GetFirstChild(xml, "cameramovements");
	new XMLNode:movementNode = XML_GetFirstChild(xml, "movement");
	while (movementNode)
	{
		if (movementIndex >= MAX_CAMERAMOVEMENTS)
		{
			printf("  Reached limit of %d camera movements", MAX_CAMERAMOVEMENTS);
			break;
		}

		new XMLNode:startNode = XML_GetFirstChild(movementNode, "start");
		if (!startNode)
		{
			print("  Missing 'start' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new XMLNode:startPositionNode = XML_GetFirstChild(startNode, "position");
		if (!startPositionNode)
		{
			print("  Missing 'position' element in 'start' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new XMLNode:startLookAtNode = XML_GetFirstChild(startNode, "lookat");
		if (!startLookAtNode)
		{
			print("  Missing 'lookat' element in 'start' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new XMLNode:endNode = XML_GetFirstChild(movementNode, "end");
		if (!endNode)
		{
			print("  Missing 'end' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new XMLNode:endPositionNode = XML_GetFirstChild(endNode, "position");
		if (!endPositionNode)
		{
			print("  Missing 'position' element in 'end' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new XMLNode:endLookAtNode = XML_GetFirstChild(endNode, "lookat");
		if (!endLookAtNode)
		{
			print("  Missing 'lookat' element in 'end' element!");

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		new type[100];
		XML_GetAttribute(movementNode, "type", type);

		if (IsStr(type, "raceLobby"))
		{
			g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_TYPE] = CAMMOVEMENT_RACELOBBY;
		}
		else
		{
			printf("  Invalid camera movement type: %s", type);

			movementNode = XML_GetNextSibling(movementNode, "movement");

			continue;
		}

		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_TIME] = XML_GetIntAttribute(movementNode, "time");

		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSX] = XML_GetFloatAttribute(startPositionNode, "x");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSY] = XML_GetFloatAttribute(startPositionNode, "y");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_POSZ] = XML_GetFloatAttribute(startPositionNode, "z");

		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATX] = XML_GetFloatAttribute(startLookAtNode, "x");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATY] = XML_GetFloatAttribute(startLookAtNode, "y");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_START_LOOKATZ] = XML_GetFloatAttribute(startLookAtNode, "z");

		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSX] = XML_GetFloatAttribute(endPositionNode, "x");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSY] = XML_GetFloatAttribute(endPositionNode, "y");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_POSZ] = XML_GetFloatAttribute(endPositionNode, "z");

		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATX] = XML_GetFloatAttribute(endLookAtNode, "x");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATY] = XML_GetFloatAttribute(endLookAtNode, "y");
		g_cameraMovements[movementIndex][E_CAMERAMOVEMENT_END_LOOKATZ] = XML_GetFloatAttribute(endLookAtNode, "z");

		movementNode = XML_GetNextSibling(movementNode, "movement");

		movementIndex++;
	}
	XML_UnloadDocument(xml);

	printf("  %d camera movements loaded", movementIndex);
}