#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

echo "TOOLSPATH = $TOOLSPATH"

pushd $TOOLSPATH/../gamemodes > /dev/null

pwd
ls -la

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"

ls -la ..
ls -la ../tools
ls -la ../tools/pawn
ls -la ../tools/pawn/pawncc

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null

pwd
ls -la
