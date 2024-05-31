cmake_minimum_required(VERSION 3.24)
project(Film)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Film main.cpp)

target_link_libraries(Film PRIVATE nlohmann_json::nlohmann_json)