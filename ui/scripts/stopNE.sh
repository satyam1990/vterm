#!/bin/bash

# inetd configuration files
INETD_CONF=/etc/inet/inetd.conf
SERVICES=/etc/inet/services

# give write permission to both conf files
chmod 755 $INETD_CONF
chmod 755 $SERVICES

# remove the wans entries from both conf files
sed '/wans_5000/d' $INETD_CONF > /tmp/inetd.new
cp /tmp/inetd.new $INETD_CONF

sed '/wans_5000/d' $SERVICES > /tmp/services.new
cp /tmp/services.new $SERVICES

# re-generate inetd configuration
inetconv -f

# remove the service entry from svcs
svcadm disable wans_5000/tcp
svccfg delete wans_5000/tcp
