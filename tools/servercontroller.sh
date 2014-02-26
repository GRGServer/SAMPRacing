#! /bin/bash

set -e

TOOLSPATH=$(dirname $0)

if [ ! -f $TOOLSPATH/tools.conf ]; then
	echo "tools.conf missing!"
	exit 1
fi

SERVER_PATH="$TOOLSPATH/.."
SERVER_EXECUTABLE="samp-srv"
SERVER_STOP_TIMEOUT=15

source $TOOLSPATH/tools.conf

function require
{
	which $1 > /dev/null 2>&1 || (echo "Command '$1' not found!"; exit 1)
}

function checkvar
{
	VALUE="${!1}"
	if [ -z "$VALUE" ]; then
		echo "${1} not defined in tools.conf!"
		exit 1
	fi
}

require start-stop-daemon

checkvar SERVER_PIDFILE
checkvar SERVER_EXEC_USER

DAEMONCMD_START="start-stop-daemon --start --pidfile $SERVER_PIDFILE --startas $SERVER_PATH/$SERVER_EXECUTABLE --chuid $SERVER_EXEC_USER --chdir $SERVER_PATH --make-pidfile --background"
DAEMONCMD_STOP="start-stop-daemon --stop --pidfile $SERVER_PIDFILE --retry $SERVER_STOP_TIMEOUT"

if [ "$VERBOSE" ]; then
	DAEMONCMD_START="$DAEMONCMD_START --verbose"
	DAEMONCMD_STOP="$DAEMONCMD_STOP --verbose"
else
	DAEMONCMD_START="$DAEMONCMD_START --quiet"
	DAEMONCMD_STOP="$DAEMONCMD_STOP --quiet"
fi

DAEMONCMD_TESTRUNNING="$DAEMONCMD_START --test"

case "$1" in
	restart)
		$0 stop
		$0 start
	;;

	start)
		echo "Starting SA-MP server..."
		$DAEMONCMD_START
		case "$?" in
			0)
				echo "Done"
			;;

			1)
				echo "Already running!"
				exit 1
			;;

			*)
				echo "Failed!"
				exit 1
			;;
		esac
	;;

	status)
		$DAEMONCMD_TESTRUNNING
		case "$?" in
			0)
				echo "SA-MP server is not running"
			;;

			1)
				echo "SA-MP server is running"
			;;

			*)
				echo "An error occurred!"
				exit 1
			;;
		esac
	;;

	stop)
		echo "Stopping SA-MP server..."
		$DAEMONCMD_START
		case "$?" in
			0)
				echo "Done"
			;;

			1)
				echo "Not running"
			;;

			*)
				echo "Failed!"
				exit 1
			;;
		esac
	;;

	*)
		echo "Usage: $0 {restart|start|status|stop}"
	;;
esac
