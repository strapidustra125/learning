#!/bin/bash

echo -e "\nBuilding project...\n"

# Очистка директории сборки
rm -R ../build && mkdir ../build

# Очистка директории с бинарниками
rm -R ../release

cd ../build


echo -e "Starting \"cmake\":\n"

#Запуск CMAKE
cmake ..

echo -e "\n\"cmake\" finished!\n\n"


echo -e "Starting \"make\":\n"

# Запуск make на nproc ядрах процессора (на всех)
make -j$(nproc)

echo -e "\n\"make\" finished!\n"