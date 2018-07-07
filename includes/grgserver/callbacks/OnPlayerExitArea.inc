OnPlayerExitArea(playerID, areaID)
{
    switch (g_areas[areaID][E_AREA_TYPE])
    {
        case AREATYPE_DRIFT:
        {
            PVar:playerID[DRIFTING_STATE] = false;
        }
    }
}