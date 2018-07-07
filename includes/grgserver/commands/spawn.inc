CMD:spawn(playerID, params[], StringID:143("Teleport yourself to the spawn location"))
{
    SetPlayerPos(playerID, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
    SetPlayerFacingAngle(playerID, SPAWN_ANGLE);
    SetPlayerInterior(playerID, SPAWN_INTERIOR);
    SetCameraBehindPlayer(playerID);

    SetPlayerVirtualWorld(playerID, 0);

    SendClientMessageEx(playerID, COLOR_INFO, StringID:144("You got teleported to the spawn location"));

    return COMMAND_OK;
}