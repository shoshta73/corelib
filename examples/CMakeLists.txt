function(add_example name)
	add_executable(${name} ${name}.cpp)
	target_link_libraries(${name} PRIVATE corelib)
endfunction()

add_example(assert)
add_example(log)
add_example(instrument)
add_example(callstack)
