cmake_minimum_required(VERSION 3.16.3)
project(NOTE_SYNC)

add_executable(${PROJECT_NAME} main.cpp curlObj.cpp jsonParsing.cpp)

#include(ExternalProject)
#include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")

#include_directories(${RAPIDJSON_INCLUDE_DIR})

#target_link_libraries(${PROJECT_NAME} rapidjson)
target_link_libraries(${PROJECT_NAME} curl)
