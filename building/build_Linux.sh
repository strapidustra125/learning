#!/bin/bash

EXECUTABLE="application"

# ------------------------------------------------------------------------------------------------ #
# Подготовка окружения

echo -e "\nSetting environment...\n"

PACKAGES=(
    make
    cmake
)

for var in ${PACKAGES[*]}
do
    INSTALLED=$(apt list ${var} 2>>/dev/null | grep installed)

    if [[ -z ${INSTALLED} ]]
    then
        echo -e "Required package \"${var}\" is NOT INSTALLED"
        echo -e "Installing...\n"
        sudo apt install -y ${var}
    else
        echo -e "Required package \"${var}\" is INSTALLED"
    fi
done

# ------------------------------------------------------------------------------------------------ #
# Сборка проекта

echo -e "\nBuilding application...\n"

# Очистка директории сборки
rm -R build
mkdir build
cd build || exit

cmake --version

#Запуск CMAKE
cmake ..

echo -e "\n\"cmake\" finished!\n"

# Запуск make на nproc ядрах процессора (на всех)
# VERBOSE=1
make -j$(nproc)

echo -e "\n\"make\" finished!\n"

# Инфо о файле
echo -e "Result file info: "
file ../${EXECUTABLE}
