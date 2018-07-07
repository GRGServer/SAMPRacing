CMD:cmds(playerID, params[], StringID:123("List all available commands"))
{
    ShowDialog:CommandList(playerID);

    return COMMAND_OK;
}