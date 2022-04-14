# Минимальная версия CMake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


# Характеристики проекта "rim_project"
set(PROJECT "strings_test")
project(${PROJECT} VERSION 1.0 LANGUAGES CXX)


# -std=c++11 - поддержка стандарта c++11
# -Wall      - выводить все варнинги
# -Wextra    - дополнительные варнинги
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")


set(SUBMODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Добавляем подмодули из директории ./source
include_directories(${SUBMODULE_SOURCES}/customStrings)
add_subdirectory(${SUBMODULE_SOURCES}/customStrings)

set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)


# Исполняемый файл

# Имя исполняемого файла для сборки
set(TARGET strings_test)

# Исполняемый файл с исходниками библиотек
add_executable(${TARGET} ${MAIN})

# Директория для сборки бинарника
set_target_properties(${TARGET} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# Линковка библиотек (ПОРЯДОК ВАЖЕН!!!!!)
target_link_libraries(${TARGET} customStrings)