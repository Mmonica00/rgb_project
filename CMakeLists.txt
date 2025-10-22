cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(pico_sdk_import.cmake)

project(rgb_project)

pico_sdk_init()

add_executable(rgb_project
    main.c
)

target_link_libraries(rgb_project pico_stdlib)

# Enable USB serial output (for printf)
pico_enable_stdio_usb(rgb_project 1)
pico_enable_stdio_uart(rgb_project 0)

pico_add_extra_outputs(rgb_project)
