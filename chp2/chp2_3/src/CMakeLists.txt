add_subdirectory(add)
add_subdirectory(mul)

add_library(math STATIC ifma.cpp)
target_include_directories(math PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(math PRIVATE add mul)