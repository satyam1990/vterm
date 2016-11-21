#!/bin/bash

# validate proper usage
if [ $# -ne 3 ]
then
	echo "Usage: $0 <wans_conf_file> <VAR_NAME> <VAR_VALUE>"
	exit -1;
fi

# store passed arguments
WANS_CONF=$1
VAR_NAME=$2
VAR_VALUE=$3

# add escape sequence for forward slashes (if any in var name)
VAR_VALUE=$(echo $VAR_VALUE | sed 's/\//\\\//g')

# update the wans conf file with new values
sed "s/^$VAR_NAME=.*$/$VAR_NAME=$VAR_VALUE/" $WANS_CONF > /tmp/wans_conf.new
cp /tmp/wans_conf.new $WANS_CONF
