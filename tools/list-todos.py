#! /usr/bin/env python3

import glob
import os

toolsPath = os.path.dirname(os.path.realpath(__file__))
serverPath = os.path.dirname(toolsPath)

files = glob.glob(os.path.join(serverPath, "includes", "grgserver", "**", "*.inc"), recursive=True)

for filePath in files:
    with open(filePath, "r") as file:
        for lineIndex, line in enumerate(file):
            index = line.find("// TODO")
            if index != -1:
                print("{} ({}): todo {}".format(filePath, lineIndex + 1, line[index + 7:].strip()))