#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

for DIR in $TOOLSPATH/*; do
	if [ -f "$DIR/pom.xml" ]; then
		$TOOLSPATH/apache-maven/bin/mvn -f $DIR clean package
	fi
done
