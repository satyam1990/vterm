#!/bin/bash

# current user
USER=$(whoami)

# WANS root directory
ROOT=$(pwd)

# directory containing binaries
BIN_DIR=$ROOT/bin

# path to telnetd
TELNETD=$BIN_DIR/emt_tgw_telnetd

# path to MO XML file
MO_FILE=$ROOT/etc/mo.xml

# path to WANS config file
WANS_CONFIG=$ROOT/etc/wans.config

# path to MML command output files directory
MML_PATH=$ROOT/mml_command_output

# default destination default IP
DD_IP=127.0.0.1

# default destination default PORT
DD_PORT=50184

# creates config file with default data
create_conf_file()
{
	echo "Creating config file"
	echo "ROOT=$ROOT" > $WANS_CONFIG
	echo "MO_FILE=$MO_FILE" >> $WANS_CONFIG;
	echo "MML_PATH=$MML_PATH" >> $WANS_CONFIG;
	echo "DD_IP=$DD_IP" >> $WANS_CONFIG;
	echo "DD_PORT=$DD_PORT" >> $WANS_CONFIG;
}

# WANS should be started as root user
if [ $USER != "root" ]
then
	echo "You need to be root to start WANS GUI!";
	exit -1;
fi

# create config file only if it does not exists
if [ ! -e $WANS_CONFIG ]
then
	create_conf_file
fi

# launch the WANS GUI
$BIN_DIR/main
