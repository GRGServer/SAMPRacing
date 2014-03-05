OnPlayerEnterArea(playerID, areaID)
{
	switch (g_areas[areaID][E_AREA_TYPE])
	{
		case AREATYPE_DRIFT:
		{
			GameTextForPlayer(playerID, LanguageString(playerID, StringID:32("Drift track")), 3000, 1);
			PVar:playerID[DRIFTING_STATE] = true;
		}
		case AREATYPE_STUNT:
		{
			GameTextForPlayer(playerID, LanguageString(playerID, StringID:126("Stunt area")), 3000, 1);
		}
	}
}