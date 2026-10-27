cmake_minimum_required(VERSION 3.10)
project(FemboyBuilder C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(FemboyBuilder ${SOURCES})

target_link_libraries(FemboyBuilder kernel32 ntdll)
