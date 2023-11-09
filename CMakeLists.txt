cmake_minimum_required(VERSION 3.26)
project(DSPD_Assignment C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        station_info.c
        utils_array.c
        main.c 
        )

add_executable(dspd_Assignment
        ${SOURCES})

set_target_properties(dspd_Assignment PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        )