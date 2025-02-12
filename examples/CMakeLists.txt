function(add_example name)
        add_executable(${name} ${name}.cpp)
        target_link_libraries(${name} corelib)
        set_target_properties(${name} PROPERTIES CXX_STANDARD 23)
        if(CMAKE_BUILD_TYPE STREQUAL "Debug")
                target_compile_definitions(
                        ${name}
                        PUBLIC
                        DEBUG=1
                        NDEBUG=0
                )
        else()
                target_compile_definitions(
                        ${name}
                        PUBLIC
                        DEBUG=0
                        NDEBUG=1
                )
        endif()
endfunction(add_example name)

add_example(logger)
