`cmake_minimum_required(VERSION 3.15 [FATAL_ERROR])`

`set(<VARIABLE NAME> <variable value>)` usage: ${<VARIABLE NAME>}

`project(<project name> LANGUAGES [CXX])` C, CXX (i.e. C++), CUDA, OBJC (i.e. Objective-C), OBJCXX, Fortran, ISPC, and ASM

`add_executable(<output file name> <source file>.[cpp|c|...])`

`cmake --build . --target [all|clean|depend|rebuild_cache|test|install|package]`

`cmake -G [Ninja|CodeBlocks|..] ..`  choose a generator

`add_library(<lib name> [STATIC|SHARED] <lib hdr name>.[hpp|h|...] <lib src name>.[cpp|c|...])`

`target_link_libraries(<target name> <lib name>)`


**targeted libs**

	add_library(%name%-obj OBJECT %name%.hpp %name%.cpp)
	add_library(%name%-shared SHARED $<TARGET_OBJECTS:%name%-obj>)
	add_library(%name%-static STATIC $<TARGET_OBJECTS:%name%-obj>)
	target_link_libraries(%targetname% %libname%)