add_subdirectory(add)
add_subdirectory(mul)

set(math_src ifma.cpp)
set(math_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(SRC ${math_src} ${add_src} ${mul_src})

add_library(math_static STATIC ${SRC})
set_target_properties(math_static PROPERTIES
    ARCHIVE_OUTPUT_NAME "math"
    PUBLIC_HEADER ${math_include_dir}/fma.h
    DEBUG_POSTFIX "_sd"
    RELEASE_POSTFIX "_s")

target_include_directories(math_static
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/math>
    PRIVATE ${add_include_dir} ${mul_include_dir})

# target_link_libraries(math PRIVATE add mul)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../install CACHE PATH "set to local path" FORCE)

# install(TARGETS math ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include/math)
install(
    TARGETS math_static
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
