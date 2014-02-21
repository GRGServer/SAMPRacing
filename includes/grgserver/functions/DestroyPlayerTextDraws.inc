DestroyPlayerTextDraws(playerID)
{
	Foreach(playerTextDraw, playerTextDraws[])
	{
		PlayerTextDrawDestroy(playerID, playerTextDraws[playerID][enum_playerTextDraws:playerTextDraw]);
	}
}