DestroyPlayerTextDraws(playerID)
{
	Count(playerTextDraw, sizeof(playerTextDraws[]))
	{
		PlayerTextDrawDestroy(playerID, playerTextDraws[playerID][enum_playerTextDraws:playerTextDraw]);
	}
}