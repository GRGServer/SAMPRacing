ResetPlayerVariables(playerID)
{
	Count(playerVariable, sizeof(playerVariables[]))
	{
		playerVariables[playerID][enum_playerVariables:playerVariable] = 0;
	}
}