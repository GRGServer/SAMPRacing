#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"
export PATH="../tools/pawn:$PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

which pawncc

pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null