#!/bin/bash

DATE=`date '+%Y-%m-%d %H:%M:%S'`
echo "Example service started at ${DATE}" | systemd-cat -p info

while :
do
	echo "Work loop ..."
	sleep 10
done

