set(mul_src ${CMAKE_CURRENT_SOURCE_DIR}/fmul.cpp ${CMAKE_CURRENT_SOURCE_DIR}/imul.cpp)
add_library(mul OBJECT ${mul_src})
target_include_directories(mul PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/math>)
set_target_properties(mul
    PROPERTIES
    POSITION_INDEPENDENT_CODE 1
    OUTPUT_NAME "mul"
    DEBUG_POSTFIX "_d"
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/mul.h"
)