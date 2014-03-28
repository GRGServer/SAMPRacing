forward ConnectNPCEx(npcID);
public ConnectNPCEx(npcID)
{
	FormatNew:name[MAX_PLAYER_NAME]("NPC_%d", npcID);

	if (GetPlayerID(name) != INVALID_PLAYER_ID)
	{
		return false;
	}

	ConnectNPC(name, NPC_SCRIPT_NAME);

	return true;
}