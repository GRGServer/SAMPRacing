ACMD:admin(playerID, params[], StringID:47("Make Admin"))
{
	PVar:playerID[ISADMIN] = true;

	return COMMAND_OK;
}