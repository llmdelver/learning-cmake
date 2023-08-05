cmake_minimum_required(VERSION 3.20)

project(chp1)

add_executable(chp1 main.cpp)

if(GENERATOR_IS_MULTI_CONFIG)
    target_compile_definitions(chp1 PRIVATE
        $<$<CONFIG:Debug>:DEBUG=1>
        $<$<CONFIG:Release>:RELEASE=1>
    )
else()
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        add_definitions(-DDEBUG)
    else()
        add_definitions(-DRELEASE)
    endif()
endif()