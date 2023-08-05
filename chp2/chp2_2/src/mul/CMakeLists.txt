set(mul_src ${CMAKE_CURRENT_SOURCE_DIR}/fmul.cpp ${CMAKE_CURRENT_SOURCE_DIR}/imul.cpp)
add_library(mul OBJECT ${mul_src})
target_include_directories(mul PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)