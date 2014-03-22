#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

file ../tools/pawn/pawncc
ldd ../tools/pawn/pawncc

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null