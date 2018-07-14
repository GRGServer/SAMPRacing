#! /usr/bin/env python3

import os

toolsPath = os.path.dirname(os.path.realpath(__file__))
serverPath = os.path.dirname(toolsPath)
subPath = "grgserver"
fullPath = os.path.join(serverPath, "includes", subPath)
lineWritten = False

mainIncFile = open(os.path.join(fullPath, "main.inc"), "w")

def writeLine(string):
    mainIncFile.write("{}\n".format(string))
    global lineWritten
    lineWritten = True

def addGroup(name):
    # Add an empty line if this is not the first line
    if lineWritten:
        writeLine("")

    writeLine("// {}".format(name))

def addInclude(name):
    writeLine("#include <{}>".format(os.path.join(subPath, name).replace("\\", "/")))

def addDirectory(path):
    addGroup(path)

    for item in sorted(os.listdir(os.path.join(fullPath, path))):
        filePath = os.path.join(fullPath, path, item)
        if not os.path.isfile(filePath):
            continue

        addInclude(os.path.join(path, item))

def main():
    addGroup("Defines")
    addInclude("constants.inc")
    addInclude("macros.inc")

    addDirectory("structures")

    addGroup("Global variables")
    addInclude("globals.inc")
    addInclude("commands.inc")
    addInclude("forwards.inc")

    addDirectory("functions")
    addDirectory("callbacks")
    addDirectory("dialogs")
    addDirectory("timers")
    addDirectory("commands")

if __name__ == "__main__":
    main()