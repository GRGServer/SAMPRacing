SetPlayerSpawn(playerID, type, Float:posX, Float:posY, Float:posZ, Float:angle = 0.0, interior = 0)
{
	PVar:playerID[SPAWN_TYPE] = type;
	PVar:playerID[SPAWN_POSX] = posX;
	PVar:playerID[SPAWN_POSY] = posY;
	PVar:playerID[SPAWN_POSZ] = posZ;
	PVar:playerID[SPAWN_ANGLE] = angle;
	PVar:playerID[SPAWN_INTERIOR] = interior;
}