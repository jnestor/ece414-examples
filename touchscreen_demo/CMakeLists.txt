cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ic_demo)

pico_sdk_init()

add_executable(ic_demo)

target_sources(ic_demo PRIVATE 
    ic_demo.c
    timer.c
    ic.c
    )

target_link_libraries(touchscreen_demo PRIVATE 
    pico_stdlib 
    pico_time  
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(touchscreen_demo)



