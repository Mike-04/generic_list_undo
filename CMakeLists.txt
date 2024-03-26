cmake_minimum_required(VERSION 3.28)
project(l4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(l4
        domain.c
        domain.h
        main.c
        repository.c
        repository.h
        service.c
        service.h
        tests.c
        tests.h
        ui.c
        ui.h
        valid.c
        valid.h
        DynamicArray.c
        DynamicArray.h
        DynamicArray.h)
