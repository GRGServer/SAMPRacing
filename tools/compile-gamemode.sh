#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

$TOOLSPATH/update-command-list.py
$TOOLSPATH/update-includes.py

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null

pushd $TOOLSPATH/../npcmodes > /dev/null

../tools/pawn/pawncc npcplayer.pwn -i../includes -\; -\(

popd > /dev/null