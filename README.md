`cmake_minimum_required(VERSION 3.15 [FATAL_ERROR])`

`set(<VARIABLE NAME> <variable value>)` usage: ${<VARIABLE NAME>}

`project(<project name> LANGUAGES [CXX])` C, CXX (i.e. C++), CUDA, OBJC (i.e. Objective-C), OBJCXX, Fortran, ISPC, and ASM

`add_executable(<output file name> <source file>.[cpp|c|...])`

`cmake --build . --target [all|clean|depend|rebuild_cache|test|install|package]`

`cmake -G [Ninja|CodeBlocks|..] ..`  choose a generator

`add_library(<lib name> [STATIC|SHARED] <lib hdr name>.[hpp|h|...] <lib src name>.[cpp|c|...])`

`target_link_libraries(<target name> <lib name>)`

---

**targeted libs**

	add_library(%name%-obj OBJECT %name%.hpp %name%.cpp)
	add_library(%name%-shared SHARED $<TARGET_OBJECTS:%name%-obj>)
	add_library(%name%-static STATIC $<TARGET_OBJECTS:%name%-obj>)
	target_link_libraries(%targetname% %libname%)

---

`message([STATUS|FATAL_ERROR|AUTHOR_WARNING|DEPRECATION|DEBUG] "<message>")`

`set(<variable name> [OFF|ON|0|1])`

`list(APPEND <variable name ['_' if local]> [<file name>.[cpp|h|...] <file name>.[cpp|h|...] ... ])`
`usage:`

	add_executable(${<target name (${PROJECT_NAME})>} <target file (main.cpp)> ${<variable name>})

---


**if-else**

	if(<some variable>)
		<cmds>
	else()
		<cmds>
	endif()

---

**environtmental variables**
	
`cmake -D CMAKE_CXX_COMPILER=clang++ ..`

`env CXX=clang++ cmake ..`

---

**BUILD TYPE**

`cmake -D CMAKE_BUILD_TYPE-[Debug|Release|MinSizeRel]`

---

**compile flags**

	list(APPEND <flags> "-<fPIC>" "-<Wall>" [...])
	if(NOT WIN32)
		list(APPEND flags "-<Wextra>" "-Wpedantic")

	target_compile_options(<target> PRIVATE ${<flags>})

---

**memory leaks tests**

	add_library(example_library leaky_implementation.cpp)
	add_executable(cpp_test test.cpp)
	target_link_libraries(cpp_test example_library)
	find_program(MEMORYCHECK_COMMAND NAMES valgrind)
	set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")
	# add memcheck test action
	include(CTest)
	# define tests
	enable_testing()
	add_test(
	  NAME cpp_test
	  COMMAND $<TARGET_FILE:cpp_test>
	)
`mkdir build && cd build && cmake .. && make && ctest -T memcheck`

---

**cmake and libpthread**

	set(THREADS_PREFER_PTHREAD_FLAG ON)
	find_package(Threads REQUIRED)
	target_link_libraries(<target name> PRIVATE Threads::Threads)