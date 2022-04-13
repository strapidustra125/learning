#!/bin/bash

echo -e "\nBuilding project...\n"

# Очистка директории сборки
rm -R ../build

mkdir ../build
mkdir ../build/buildTemp

cd ../build/buildTemp || exit


echo -e "Starting \"cmake\" for project:\n"

#Запуск CMAKE
cmake -DTOOLCHAIN_FLAG=OFF ../../

echo -e "\n\"cmake\" for project finished!\n\n"


echo -e "Starting \"make\" for project:\n"

# Запуск make на nproc ядрах процессора (на всех)
make -j$(nproc)

echo -e "\n\"make\" for project finished!\n"

# Инфо о файле
echo -n "Result file info: " 
file ../rimModule