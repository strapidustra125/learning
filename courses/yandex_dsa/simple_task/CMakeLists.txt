# Минимальная версия CMake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


set(PROJECT "course")
project(${PROJECT} VERSION 1.0 LANGUAGES CXX)


# -std=c++11 - поддержка стандарта c++11
# -Wall      - выводить все варнинги
# -Wextra    - дополнительные варнинги
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

add_definitions(-DMY_IDE -D__cplusplus=201703L)



# Исполняемый файл с исходниками библиотек
add_executable(${TARGET} ${TARGET}.cpp)

# Директория для сборки бинарника
set_target_properties(${TARGET} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)

