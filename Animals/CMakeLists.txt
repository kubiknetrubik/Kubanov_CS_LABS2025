cmake_minimum_required(VERSION 3.23)

set(project "Animals")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        animals.cpp mammals.cpp artiodactyls.cpp birds.cpp)

set(${project}_HEADERS
        animals.hpp mammals.hpp artiodactyls.hpp birds.hpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
