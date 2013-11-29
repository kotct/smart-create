#!/bin/bash

case $1 in
	".h" | "h")
	patext=".h"
	;;

	* |".c" | "c")
	patext=".c"
	;;
esac


output_string=""

for i in `find src/*$patext`; do
	filename=$(basename "$i")
	module=${filename%.*}

	output_string="$output_string $module"
done

echo $output_string
