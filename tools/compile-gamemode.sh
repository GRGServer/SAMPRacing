#! /bin/bash

TOOLSPATH=$(dirname $0)
ROOTPATH="$TOOLSPATH/.."

wine $TOOLSPATH/pawn/pawncc.exe $ROOTPATH/gamemodes/grgserver.pwn -i$ROOTPATH/includes -o$ROOTPATH/gamemodes/grgserver.amx -\; -\(
