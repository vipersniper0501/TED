cmake_minimum_required(VERSION 3.16.3)
project (ted VERSION 0.0.1)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

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
