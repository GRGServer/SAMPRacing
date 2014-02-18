CMD:admin(playerID, params[], 0)
{
	PVar:playerID[ISADMIN] = true;

	return COMMAND_OK;
}