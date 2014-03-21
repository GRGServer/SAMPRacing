#! /bin/bash

TOOLSPATH=$(dirname $0)

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null
