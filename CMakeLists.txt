cmake_minimum_required(VERSION 3.27)
project(knnml_airbnb C)

set(CMAKE_C_STANDARD 11)

add_executable(knnml_airbnb main.c
        src/csv_manager.c
        src/csv_manager.h
        src/knnml.c
        src/knnml.h
        src/my_print.c
        src/my_print.h)