cmake_minimum_required(VERSION 3.23)

set(project "Term")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        term.cpp)

set(${project}_HEADERS
        term.hpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
