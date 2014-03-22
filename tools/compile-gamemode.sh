#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="$TOOLSPATH/pawn:$LD_LIBRARY_PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null
