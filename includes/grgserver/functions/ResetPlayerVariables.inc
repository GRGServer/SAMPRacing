ResetPlayerVariables(playerID)
{
	Count(playerVariable, sizeof(playerVariables[]))
	{
		playerVariables[playerID][enum_playerVariable:playerVariable] = 0;
	}
}