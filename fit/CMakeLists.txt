cmake_minimum_required(VERSION 3.27)
project(fit C)

set(CMAKE_C_STANDARD 99)

add_executable(fit main.c
        partita.h
        lista.h
        nodo.h)
