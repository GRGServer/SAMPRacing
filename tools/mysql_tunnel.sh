#! /bin/sh

TOOLSPATH=$(dirname $0)

`sed -nr "s/#define ([a-zA-Z0-9_]+)\s+\"(.*)\"/export \1=\2/p" ${TOOLSPATH}/../includes/grgserver/localconfig.inc`

if [ ! -f $TOOLSPATH/tools.conf ]; then
	echo "tools.conf missing!"
	exit 1
fi

source $TOOLSPATH/tools.conf

echo "Forwarding port $MYSQL_TUNNEL_REMOTEPORT on $MYSQL_TUNNEL_SSHSERVER to $MYSQL_TUNNEL_LOCALHOST:$MYSQL_TUNNEL_LOCALPORT on the local side"
echo ""
echo "Do not close this script while using the tunnel!"

ssh -N -R $MYSQL_TUNNEL_REMOTEPORT:$MYSQL_TUNNEL_LOCALHOST:$MYSQL_TUNNEL_LOCALPORT $MYSQL_TUNNEL_SSHSERVER