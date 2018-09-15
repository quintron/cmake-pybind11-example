cmake_minimum_required(VERSION 3.5)
project(myproject VERSION 1.0.0 LANGUAGES CXX)

#Myproject Lib
add_library(myproject_lib
			src/add.h
			src/add.cpp
)
set_target_properties(myproject_lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(myproject_lib PUBLIC 
		PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
		PRIVATE $<INSTALL_INTERFACE:src>)
		
		
#Google testing
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(lib/googletest)
add_executable(myproject_test 
				tests/add_test.cpp)
target_link_libraries(myproject_test gtest gmock_main myproject_lib)
add_test(NAME myproject_test COMMAND myproject_test)
enable_testing()
		
		
#Myproject python
add_subdirectory(lib/pybind11)
pybind11_add_module(myproject main.cpp)
target_link_libraries(myproject PUBLIC myproject_lib)
