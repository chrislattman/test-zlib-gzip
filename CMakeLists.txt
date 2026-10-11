cmake_minimum_required(VERSION 3.22)
project(test-zlib-gzip VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(ZLIB REQUIRED)

add_executable(compression compression.c)
target_link_libraries(compression PRIVATE ZLIB::ZLIB)

add_custom_target(run-compression
    COMMAND compression
    DEPENDS compression
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    USES_TERMINAL
    VERBATIM
)
