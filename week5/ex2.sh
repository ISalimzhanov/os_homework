#!/bin/bash
file=ex2.txt
if [[ $? -ne 0 ]]; then
	echo "File is locked"
	exit -1
fi

ln $file "$file.lock"

trap ctrl_c INT

function ctrl_c() {
        echo "Unlocking and exiting"
	rm -f "$file.lock"
	exit 0
}

while true; do
	x=$(cat $file | tr ' ' "\n" | tail -n 1)
	printf "%d " $(($x + 1)) >> $file
done
