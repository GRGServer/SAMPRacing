#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

pushd $TOOLSPATH/../gamemodes > /dev/null

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null
