#!/bin/bash

for i in {2..9}
do
	for j in {1..9}
	do
		let k=i*j
		echo $i "*" $j ":" $k
	done
done	
