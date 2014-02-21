ResetPlayerVariables(playerID)
{
	Foreach(playerVariable, playerVariables[])
	{
		playerVariables[playerID][enum_playerVariables:playerVariable] = 0;
	}
}