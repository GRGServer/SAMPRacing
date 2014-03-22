#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="$TOOLSPATH/pawn:$LD_LIBRARY_PATH"
export PATH="$TOOLSPATH/pawn:$PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

which pawncc

pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null