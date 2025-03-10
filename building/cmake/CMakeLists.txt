# Минимальная версия CMake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJECT "application")
project(${PROJECT} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")


# ------------------------------------------------------------------------------------------------ #
# Подготовка библиотек и переменных

# Работа с библиотекой thread
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)


# ------------------------------------------------------------------------------------------------ #
# Подключение исходников приложения

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


# ------------------------------------------------------------------------------------------------ #
# Сборка исполняемого файла

add_executable( ${PROJECT} ${SOURCES} )

# Директория для сборки бинарника
set_target_properties(${PROJECT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
