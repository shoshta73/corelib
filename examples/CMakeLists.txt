function(add_example name)
        add_executable(${name} ${name}.cpp)
        target_link_libraries(${name} corelib)
endfunction(add_example name)

add_example(hello)
