cmake_minimum_required(VERSION 3.10)

project(rp2040_devtool)

set(CMAKE_SYSTEM_NAME Linux)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lvgl/*.h" "lv_drivers/*.h"  "./*.h")
file(GLOB_RECURSE SOURCES  "lvgl/src/*.c" "lv_drivers/*.c" "./mouse_cursor_icon.c")

add_executable(rp2040_devtool main.c ${SOURCES} ${INCLUDES})

add_subdirectory(src/picoboot_connection)
# add_subdirectory(hal)
add_subdirectory(ui)
add_subdirectory(tests)

set(CMAKE_BUILD_TYPE "Release")

target_include_directories(rp2040_devtool PUBLIC "include")
target_link_libraries(rp2040_devtool ui SDL2 pthread picoboot_connection usb-1.0
        asound tinyalsa pthread swscale avformat avcodec avutil avfilter swresample)