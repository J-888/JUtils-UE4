#!/bin/bash

# Copyright (C) 2021 Jose Miguel Tajuelo
# This file is part of the project "JUtils Unreal Engine 4"
# and is subject to the terms and conditions defined in it
# 
# For updates, licensing, and more information, visit:
# https://github.com/J-888/JUtils-UE4
# https://JTajuelo.com/

autogen_proj_dirs=(
	"Binaries/"
	"Intermediate/"
	"Saved/"
)

autogen_plugin_dirs=(
	"Binaries"
	"Intermediate"
)

declare -a delete_targets

for dir in ${autogen_proj_dirs[@]}; do
	if [ -d "${dir}" ]; then
		delete_targets+=(${dir})
	fi
done

if [ -d "Plugins" ]; then
	for plugin in Plugins/*; do
		if [ -d "$plugin" ]; then
			for dir in ${autogen_plugin_dirs[@]}; do
				if [ -d "${plugin}/${dir}" ]; then
					delete_targets+=(${plugin}/${dir})
				fi
			done
		fi
	done
fi

if [ "${#delete_targets[@]}" -ne 0 ]; then
	printf "The following directories will be deleted:\n\n"
	printf "%s\n" "${delete_targets[@]}"
	echo
	read -p "Are you sure? [y/N] " -n 1 -r
	echo

	if [[ $REPLY =~ ^[Yy]$ ]]; then
		echo "Deleting..."
		for dir in ${delete_targets[@]}; do
			rm -r "$dir"
		done
	fi
else
	echo 'Nothing to delete'
fi
