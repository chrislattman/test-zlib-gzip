cmake_minimum_required(VERSION 3.22)
project(test-zlib-gzip C)

find_package(ZLIB REQUIRED)

add_executable(compression compression.c)
target_link_libraries(compression PRIVATE ZLIB::ZLIB)

add_custom_target(run-compression
    COMMAND compression
    DEPENDS compression
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
)
