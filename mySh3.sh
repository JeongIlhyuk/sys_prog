#!/bin/bash

i=2
while [ "$i" -lt 10 ]
do
	j=1
	while [ "$j" -lt 10 ]
	do
		let k=i*j
		echo "$i * $j : $k"
		let j=j+1
	done
	let i=i+1
done

