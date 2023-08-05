add_subdirectory(add)
add_subdirectory(mul)

add_library(math STATIC ${add_src} ${mul_src})
target_include_directories(math PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/add/include
    ${CMAKE_CURRENT_SOURCE_DIR}/mul/include)