set(add_src ${CMAKE_CURRENT_SOURCE_DIR}/fadd.cpp ${CMAKE_CURRENT_SOURCE_DIR}/iadd.cpp)
add_library(add OBJECT ${add_src})
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)