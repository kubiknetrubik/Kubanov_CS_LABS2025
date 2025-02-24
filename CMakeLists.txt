cmake_minimum_required(VERSION 3.23)

set(project "lab3")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction.hpp
)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
