forward OnScreenFaderEnded(playerID);
public OnScreenFaderEnded(playerID)
{
	if (PVar:playerID[SCREENFADER_FADEOUT])
	{
		switch (PVar:playerID[SCREENFADER_ID])
		{
			case SCREENFADER_TELEPORT:
			{
				TeleportTo(playerID, PVar:playerID[TELEPORTID], true);
			}
		}
	}
	else
	{
		TogglePlayerControllable(playerID, true);
	}
}