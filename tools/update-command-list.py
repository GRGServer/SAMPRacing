#! /usr/bin/env python3

import os
import re

toolsPath = os.path.dirname(os.path.realpath(__file__))
serverPath = os.path.dirname(toolsPath)
grgIncludesPath = os.path.join(serverPath, "includes", "grgserver")
commandsPath = os.path.join(grgIncludesPath, "commands")
pattern = re.compile("^(PCMD|CMD):(?P<name>[a-z]+)(\\[(?P<pvar>[A-Z_]+)\\])?\\(playerID, params\\[\\], StringID:(?P<stringid>[0-9]+)\\(\"(.*)\"\\)\\)")

commands = []

for item in os.listdir(commandsPath):
    filePath = os.path.join(commandsPath, item)
    if not os.path.isfile(filePath):
        continue

    with open(filePath, "r") as file:
        for line in file:
            match = pattern.match(line.strip())
            if match is None:
                continue

            pvar = match.group("pvar")

            if pvar is None:
                pvar = ""

            commands.append({
                "name": match.group("name"),
                "pvar": pvar,
                "stringid": match.group("stringid")
            })

commands = sorted(commands, key=lambda command: command["name"])

with open(os.path.join(grgIncludesPath, "commands.inc"), "w") as commandsFile:
    commandsFile.write("new g_commands[][E_COMMAND] = {\n")
    for index, command in enumerate(commands):
        commandsFile.write("    {{{stringid}, \"{name}\", \"{pvar}\"}}".format_map(command))

        if index < len(commands) - 1:
            commandsFile.write(",")

        commandsFile.write("\n")
    commandsFile.write("};")