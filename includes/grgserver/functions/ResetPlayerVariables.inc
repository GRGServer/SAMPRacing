ResetPlayerVariables(playerID)
{
	Foreach(playerVariable, g_playerVariables[])
	{
		g_playerVariables[playerID][E_PVAR:playerVariable] = 0;
	}
}