add_subdirectory(add)
add_subdirectory(mul)

set(math_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(math_shared SHARED ifma.cpp)
target_link_libraries(math_shared PRIVATE add mul)

set_target_properties(math_shared PROPERTIES
    ARCHIVE_OUTPUT_NAME "math"
    PUBLIC_HEADER ${math_include_dir}/fma.h
    DEBUG_POSTFIX "_d"
    RELEASE_POSTFIX "")

target_include_directories(math_shared
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/math>
    PRIVATE ${add_include_dir} ${mul_include_dir})

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../install CACHE PATH "set to local path" FORCE)

install(
    TARGETS math_shared add mul
    EXPORT mathTargets
    ARCHIVE DESTINATION lib COMPONENT lib
    RUNTIME DESTINATION bin COMPONENT bin
    LIBRARY DESTINATION lib COMPONENT lib
    PUBLIC_HEADER DESTINATION include/math COMPONENT dev
)

set(cmake_dir ${CMAKE_INSTALL_PREFIX}/cmake)
install(EXPORT mathTargets
    NAMESPACE "math::"
    DESTINATION ${cmake_dir}
    COMPONENT dev
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/mathConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/mathConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/mathConfig.cmake
    INSTALL_DESTINATION ${cmake_dir}
)
install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/mathConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/mathConfigVersion.cmake
    DESTINATION
    ${cmake_dir}
)