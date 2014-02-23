DestroyPlayerTextDraws(playerID)
{
	Foreach(playerTextDraw, g_playerTextDraws[])
	{
		PlayerTextDrawDestroy(playerID, g_playerTextDraws[playerID][E_PTD:playerTextDraw]);
	}
}