cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_C_FLAGS "-g -Wall -Wformat-security -Wstrict-overflow -Wsign-compare -Wempty-body -Wignored-qualifiers -Wuninitialized -Wtype-limits -Woverride-init -Wno-multichar -Wno-attributes -Wnull-dereference")
project (ted VERSION 0.0.1)

if (GCC)
    add_compile_options(-g -Wall -Wformat-security -Wstrict-overflow -Wsign-compare -Wempty-body -Wignored-qualifiers -Wuninitialized -Wtype-limits -Woverride-init -Wno-multichar -Wno-attributes -Wnull-dereference)
elseif (MSVC)
    add_compile_options(/W4 /WX)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Bring the headers into the project
include_directories(include)

file(GLOB SOURCES "src/*.c")


add_executable(ted ${SOURCES})
