#!/bin/bash

# validate proper usage
if [ $# -ne 1 ]
then
	echo "Usage: $0 <WANS_BIN_DIR_PATH>"
	exit -1;
fi

# inetd configuration files
INETD_CONF=/etc/inet/inetd.conf
SERVICES=/etc/inet/services

# wans bin dir path
BIN_DIR=$1

# give write permission to both conf files
chmod 755 $INETD_CONF
chmod 755 $SERVICES

# write wans entry in both files
echo "wans_5000     stream   tcp     nowait  root $BIN_DIR/emt_tgw_telnetd emt_tgw_telnetd -h -P $BIN_DIR" >> $INETD_CONF
echo "wans_5000     5000/tcp" >> $SERVICES

# re-generate inetd configuration
inetconv -f

# verify wans service state
state=$(svcs -a | grep wans_5000 | awk '{ print $1 }')
if [ "$state" != "online" ]
then
	# enable the service as not already in online state
	svcadm disable wans_5000/tcp
	svcadm enable wans_5000/tcp
fi
