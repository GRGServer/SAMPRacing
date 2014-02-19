OnPlayerCommandPerformed(playerID, command[], parameters[], returnCode)
{
	switch (returnCode)
	{
		case COMMAND_ERROR:
		{
			PlaySound(playerID, SOUND_COMMAND_ERROR);
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:11("An error occurred while processing the command!"));
		}
		case COMMAND_NOT_FOUND:
		{
			PlaySound(playerID, SOUND_COMMAND_ERROR);
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:12("Command not found!"));
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:13("Use /cmds to see a list of commands"));
		}
		case COMMAND_NOT_IN_VEHICLE:
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:14("You are not in a vehicle!"));
		}
		case COMMAND_NOT_VEHICLE_DRIVER:
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:19("You are not the driver of this vehicle!"));
		}
		case COMMAND_OK:
		{
			PlaySound(playerID, SOUND_COMMAND_OK);
		}
		case COMMAND_OK_NOSOUND:
		{
			// Command executed successfully -> Do nothing
		}
		case COMMAND_PERMISSION_DENIED:
		{
			PlaySound(playerID, SOUND_COMMAND_DENIED);
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:15("You do not have the required permissions to use this command!"));
			printf("%s tried to execute /%s but has not the required permission!", GetPlayerNameEx(playerID), command);
		}
		case COMMAND_PLAYER_NOT_FOUND:
		{
			SendClientMessageEx(playerID, COLOR_ERROR, StringID:16("Player not found!"));
		}
		case COMMAND_TELEPORTED:
		{
			SendClientMessageEx(playerID, COLOR_INFO, StringID:17("You got teleported"));
		}
		case COMMAND_USAGE:
		{
			// Command usage message displayed -> Nothing to do yet
		}
		default:
		{
			printf("Unknown command return code from /%s: %d", command, returnCode);
			return false;
		}
	}
	return true;
}