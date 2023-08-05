add_subdirectory(add)
add_subdirectory(mul)

add_library(math STATIC)
target_link_libraries(math PRIVATE add mul)