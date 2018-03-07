cmake_minimum_required(VERSION 3.9)
project(CHash C)

set(CMAKE_C_STANDARD 99)

add_executable(CHash main.c Hash_Table.h Hash_Table.c Hash_Table.h)