OnPlayerExitArea(playerID, areaID)
{
	switch (g_areas[areaID][E_AREA_GROUP])
	{
		case AREAGROUP_DRIFT:
		{
			PVar:playerID[DRIFTING_STATE] = false;
		}
	}
}