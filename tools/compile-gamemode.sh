#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

export LD_LIBRARY_PATH="../tools/pawn:$LD_LIBRARY_PATH"

$TOOLSPATH/apache-maven/bin/mvn -f $TOOLSPATH/includesupdater/pom.xml clean package

java -jar $TOOLSPATH/includesupdater/target/includesupdater.jar

pushd $TOOLSPATH/../gamemodes > /dev/null

../tools/pawn/pawncc grgserver.pwn -i../includes -\; -\(

popd > /dev/null

pushd $TOOLSPATH/../npcmodes > /dev/null

../tools/pawn/pawncc npcplayer.pwn -i../includes -\; -\(

popd > /dev/null