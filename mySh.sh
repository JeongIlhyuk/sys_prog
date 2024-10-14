#!/bin/bash

income=100000

if [ "$income" -lt 50000 ]; then
	echo "your income will be increased about 5 percent"
elif [ "$income" -lt 90000 ]; then
	echo "your income will be increased about 3 percent"
else
	echo "your income will be increased about 1 percent"
fi
