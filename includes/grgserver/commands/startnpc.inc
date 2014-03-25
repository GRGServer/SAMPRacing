PCMD:startnpc[ISADMIN](playerID, params[], StringID:195("Start the NPC"))
{

	SendClientMessageEx(playerID, COLOR_INFO, StringID:196("NPCs have ben Joined!"));

	return COMMAND_OK;
}