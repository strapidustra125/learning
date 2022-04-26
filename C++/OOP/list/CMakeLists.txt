# Минимальная версия CMake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


# Характеристики проекта "rim_project"
set(PROJECT "tree_test")
project(${PROJECT} VERSION 1.0 LANGUAGES CXX)


# -std=c++11 - поддержка стандарта c++11
# -Wall      - выводить все варнинги
# -Wextra    - дополнительные варнинги
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")


set(SUBMODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(STRINGS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../strings/source/customStrings)

# Добавляем подмодули из директории ./source
include_directories(${STRINGS_SOURCES})

set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)


# Исполняемый файл

# Имя исполняемого файла для сборки
set(TARGET ${PROJECT})

# Исполняемый файл с исходниками библиотек
add_executable(${TARGET} 
                ${MAIN}
                ${STRINGS_SOURCES}/customStrings.cpp
                )

# Директория для сборки бинарника
set_target_properties(${TARGET} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)
