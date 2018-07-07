TeleportToInterior(playerID, interiorID)
{
    if (interiorID < 0 || interiorID >= MAX_INTERIORS)
    {
        return false;
    }

    SetPlayerPos(playerID, g_interiors[interiorID][E_INTERIOR_POSX], g_interiors[interiorID][E_INTERIOR_POSY], g_interiors[interiorID][E_INTERIOR_POSZ]);
    SetPlayerFacingAngle(playerID, g_interiors[interiorID][E_INTERIOR_ANGLE]);
    SetPlayerInterior(playerID, g_interiors[interiorID][E_INTERIOR_ID]);
    SetCameraBehindPlayer(playerID);

    return true;
}