cmake_minimum_required(VERSION 3.27)
project(pizzeria C)

set(CMAKE_C_STANDARD 99)

add_executable(pizzeria main.c
        ordine.h
        pronte.h)
