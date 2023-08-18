set(add_src ${CMAKE_CURRENT_SOURCE_DIR}/fadd.cpp ${CMAKE_CURRENT_SOURCE_DIR}/iadd.cpp)
add_library(add STATIC ${add_src})
target_include_directories(add PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/math>)
set_target_properties(add
    PROPERTIES

    # POSITION_INDEPENDENT_CODE 1
    OUTPUT_NAME "add"
    DEBUG_POSTFIX "_d"
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/add.h"
)
target_compile_options(add PRIVATE "-mcmodel=large")
install(
    FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/add.h
    DESTINATION include/math
)