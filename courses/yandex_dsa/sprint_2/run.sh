#!/bin/bash

ARG=$1
if [[ ${ARG} == "" ]]
then
    echo -e "\nError: Script must have the argument: name of source!\n"
    exit
fi

cd ./build || exit

echo -e "\nRunning program...\n"

./${ARG}