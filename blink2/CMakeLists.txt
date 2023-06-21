cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project)

pico_sdk_init()

add_executable(test0
        test0.c
        )

# pull in common dependencies
target_link_libraries(test0 pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(test0)

