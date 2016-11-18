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

# term script file
TERM_SCRIPT=$BIN_DIR/term

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
	echo "BIN_DIR=$BIN_DIR" >> $WANS_CONFIG
	echo "MO_FILE=$MO_FILE" >> $WANS_CONFIG
	echo "MML_PATH=$MML_PATH" >> $WANS_CONFIG
	echo "DD_IP=$DD_IP" >> $WANS_CONFIG
	echo "DD_PORT=$DD_PORT" >> $WANS_CONFIG
}

# creates term script file which will be executed by inted
create_term_script()
{
	echo "#!/bin/bash" > $TERM_SCRIPT
	echo "" >> $TERM_SCRIPT
	echo "# set the library path" >> $TERM_SCRIPT
	echo "export LD_LIBRARY_PATH=/opt/ericsson/lib" >> $TERM_SCRIPT
	echo "" >> $TERM_SCRIPT
	echo "# start the actual binary" >> $TERM_SCRIPT
	echo "$BIN_DIR/vterm $WANS_CONFIG" >> $TERM_SCRIPT

	# provide execute permission
	chmod 755 $TERM_SCRIPT
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
	create_term_script
fi

# launch the WANS GUI
$BIN_DIR/main $WANS_CONFIG
