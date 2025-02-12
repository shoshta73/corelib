cmake_minimum_required(VERSION 3.10)

project(
        corelib
        VERSION 0.0.0.0
        DESCRIPTION "Corelib"
        LANGUAGES CXX
)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(
        ${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_definitions(
                ${PROJECT_NAME}
                PUBLIC
                DEBUG=1
                NDEBUG=0
        )
else()
        target_compile_definitions(
                ${PROJECT_NAME}
                PUBLIC
                DEBUG=0
                NDEBUG=1
        )
endif()


add_subdirectory(examples)
