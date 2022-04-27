# Минимальная версия CMake
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Определение ОС для корректной сборки файла getch.h 
if(WIN32)
        message("---> Target OS is: Windows")
        add_definitions(-DWINDOWS)
elseif(UNIX)
        message("---> Target OS is: Linux")
        add_definitions(-DLINUX)
else()
	message(FATAL_ERROR "Unknown OS!!!!")
endif()


# Характеристики проекта "rim_project"
set(PROJECT "strings_test")
project(${PROJECT} VERSION 1.0 LANGUAGES CXX)


# -std=c++11 - поддержка стандарта c++11
# -Wall      - выводить все варнинги
# -Wextra    - дополнительные варнинги
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")


set(SUBMODULE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(STRINGS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../strings/source/customStrings)
set(HELPING_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../../helping)

# Добавляем подмодули из директории ./source
include_directories(${STRINGS_SOURCES})
include_directories(${HELPING_SOURCES})
include_directories(${SUBMODULE_SOURCES}/console)
include_directories(${SUBMODULE_SOURCES}/helping)


add_subdirectory(${SUBMODULE_SOURCES}/console)

set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)





# Исполняемый файл

# Имя исполняемого файла для сборки
set(TARGET console_test)

# Исполняемый файл с исходниками библиотек
add_executable(${TARGET} 
        ${MAIN}
        ${STRINGS_SOURCES}/customStrings.cpp
        ${HELPING_SOURCES}/helping.cpp
)



# Директория для сборки бинарника
set_target_properties(${TARGET} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)

# Линковка библиотек (ПОРЯДОК ВАЖЕН!!!!!)
target_link_libraries(${TARGET} console)
