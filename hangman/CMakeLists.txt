cmake_minimum_required(VERSION 3.27)
project(hangman C)

set(CMAKE_C_STANDARD 90)

add_executable(hangman main.c
        helper.h
)
