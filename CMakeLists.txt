cmake_minimum_required(VERSION 3.10)

project(rp2040_devtool)

add_executable(rp2040_devtool main.c)

add_subdirectory(src/picoboot_connection)
target_include_directories(rp2040_devtool PUBLIC "include")
target_link_libraries(rp2040_devtool picoboot_connection usb-1.0)