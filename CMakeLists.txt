cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassDoer.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassDoer.hpp
)

add_subdirectory(planet)
add_subdirectory(mymat)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g3)
endif()
target_link_libraries(${project} planet)
target_link_libraries(${project} mymat)
