#! /bin/bash

TOOLSPATH=$(dirname $0)

pushd $TOOLSPATH/../gamemodes > /dev/null

wine ../tools/pawn/pawncc.exe grgserver.pwn -i../includes -\; -\(

popd > /dev/null
