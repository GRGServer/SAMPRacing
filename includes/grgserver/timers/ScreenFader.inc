Timer:ScreenFader(playerID)
{
	if (PVar:playerID[SCREENFADER_FADEOUT])
	{
		if (PVar:playerID[SCREENFADER_COLOR_ALPHA] >= 255)
		{
			KillTimer(PVar:playerID[SCREENFADER_TIMER]);
			OnScreenFaderEnded(playerID);
		}
		else
		{
			PVar:playerID[SCREENFADER_COLOR_ALPHA] += PVar:playerID[SCREENFADER_STEPS];
		}

		if (PVar:playerID[SCREENFADER_COLOR_ALPHA] > 255)
		{
			PVar:playerID[SCREENFADER_COLOR_ALPHA] = 255;
		}
	}
	else
	{
		if (PVar:playerID[SCREENFADER_COLOR_ALPHA] <= 0)
		{
			KillTimer(PVar:playerID[SCREENFADER_TIMER]);
			OnScreenFaderEnded(playerID);
		}
		else
		{
			PVar:playerID[SCREENFADER_COLOR_ALPHA] -= PVar:playerID[SCREENFADER_STEPS];
		}

		if (PVar:playerID[SCREENFADER_COLOR_ALPHA] < 0)
		{
			PVar:playerID[SCREENFADER_COLOR_ALPHA] = 0;
		}
	}

	PlayerTextDrawBoxColor(playerID, g_playerTextDraws[playerID][E_PTD_SCREENFADER], GetColor(PVar:playerID[SCREENFADER_COLOR_RED], PVar:playerID[SCREENFADER_COLOR_GREEN], PVar:playerID[SCREENFADER_COLOR_BLUE], PVar:playerID[SCREENFADER_COLOR_ALPHA]));

	if (PVar:playerID[SCREENFADER_COLOR_ALPHA])
	{
		PlayerTextDrawShow(playerID, g_playerTextDraws[playerID][E_PTD_SCREENFADER]);
	}
	else
	{
		PlayerTextDrawHide(playerID, g_playerTextDraws[playerID][E_PTD_SCREENFADER]);
	}
}