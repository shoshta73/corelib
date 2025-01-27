function(add_example name)
	add_executable(${name} ${name}.cpp)
	target_link_libraries(${name} PRIVATE corelib)
endfunction()

add_example(hello)
add_example(assert)
add_example(log)
