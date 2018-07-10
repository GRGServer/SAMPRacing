public OnPlayerDeath(playerid, killerid, reason)
{
    SendDeathMessage(killerid, playerid, reason);

    new Float:posX;
    new Float:posY;
    new Float:posZ;
    GetPlayerPos(playerid, posX, posY, posZ);

    new pickupID = GetClosestPickup(posX, posY, posZ, PICKUPTYPE_HOSPITAL);

    GetDynamicPickupPos(pickupID, posX, posY, posZ);

    SetPlayerSpawn(playerid, SPAWNTYPE_DEFAULT, posX, posY, posZ);
}