public OnPlayerDeath(playerid, killerid, reason)
{
    SendDeathMessage(killerid, playerid, reason);

    new Float:posX;
    new Float:posY;
    new Float:posZ;
    GetPlayerPos(playerid, posX, posY, posZ);

    new pickupID = GetClosestPickup(posX, posY, posZ, PICKUPTYPE_HOSPITAL);

    SetPlayerSpawn(playerid, SPAWNTYPE_DEFAULT, g_pickups[pickupID][E_PICKUP_POSX], g_pickups[pickupID][E_PICKUP_POSY], g_pickups[pickupID][E_PICKUP_POSZ]);
}