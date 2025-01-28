function(add_example name)
	add_executable(${name} ${name}.cpp)
	target_link_libraries(${name} PRIVATE corelib)
endfunction()

add_example(assert)
set_build_type_defines(assert)

add_example(instrument)
set_build_type_defines(instrument)

add_example(callstack)
set_build_type_defines(callstack)

add_example(auto_release)
set_build_type_defines(auto_release)

add_example(binder)
set_build_type_defines(binder)

