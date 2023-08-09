cmake_minimum_required(VERSION 3.20)

project(chp3_main)

set(module_relative_path ${CMAKE_CURRENT_SOURCE_DIR}/../install/cmake)

list(APPEND CMAKE_PREFIX_PATH ${module_relative_path})

# set(math_DIR ${module_relative_path})
add_executable(main main.cpp)

find_package(math 1.0.0 REQUIRED)

target_include_directories(main PRIVATE ${math_include_dir})
target_link_libraries(main math::math_static)