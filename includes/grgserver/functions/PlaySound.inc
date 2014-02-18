PlaySound(playerID, soundID)
{
	new Float:posX;
	new Float:posY;
	new Float:posZ;
	GetPlayerPos(playerID, posX, posY, posZ);
	PlayerPlaySound(playerID, soundID, posX, posY, posZ);
}