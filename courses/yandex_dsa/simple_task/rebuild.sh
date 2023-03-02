#!/bin/bash

echo -e "\nBuilding...\n"

# Очистка директории сборки
rm -R ./build

ARG="task"

mkdir ./build

cd ./build || exit

echo -e "Starting \"cmake\":\n"

#Запуск CMAKE
cmake -DTARGET=${ARG} ..

echo -e "\n\"cmake\" finished!\n\n"


echo -e "Starting \"make\":\n"

# Запуск make на nproc ядрах процессора (на всех)
make -j$(nproc)

echo -e "\n\"make\" finished!\n"

cd ../

./run.sh ${ARG}