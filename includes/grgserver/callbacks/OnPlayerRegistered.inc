forward OnPlayerRegistered(playerID);
public OnPlayerRegistered(playerID)
{
    PVar:playerID[USERID] = cache_insert_id();

    SendClientMessageEx(playerID, COLOR_INFO, StringID:41("Your registration was successful"));

    // Send login message to all players except the logged in player
    PlayerLoop(currentPlayerID)
    {
        if (currentPlayerID != playerID)
        {
            SendClientMessageEx(currentPlayerID, COLOR_JOINLEAVE, StringID:26("%u logged in"), playerID);
        }
    }

    // Load the player
    LoadPlayer(playerID);
}