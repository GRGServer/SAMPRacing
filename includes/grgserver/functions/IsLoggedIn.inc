IsLoggedIn(playerID)
{
	return (IsPlayerConnected(playerID) && !IsPlayerNPC(playerID) && PVar:playerID[USERID]);
}