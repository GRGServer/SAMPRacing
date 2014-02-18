/**
 * <summary>
 *	Execute a player command (e.g. spawnvehicle Infernus)
 * </summary>
 *
 * <param name="playerID">
 *	The ID of the player which executes the command
 * </param>
 *
 * <param name="command">
 *	Name of the command to execute (e.g. spawnvehicle)
 * </param>
 *
 * <param name="parameters">
 *	The parameters passed to the command (e.g. Infernus)
 * </param>
 *
 * <returns>
 *	Return true if the command has been progressed or false if an error occured
 * </returns>
 *
 * <remarks>
 *	Currently only invalid return codes are handled as errors (return false)!
 * </remarks>
 */

ExecuteCommand(playerID, command[], parameters[])
{
	FormatNew:functionName[MAX_FUNCTION_NAME]("cmd_%s", command);
	new returnCode = COMMAND_NOT_FOUND;
	if (funcidx(functionName) != -1)
	{
		if (StrNotNull(parameters))
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, parameters);
		}
		else
		{
			returnCode = CallLocalFunction(functionName, "ds", playerID, "\1");
		}
	}
	return OnPlayerCommandPerformed(playerID, command, parameters, returnCode);
}