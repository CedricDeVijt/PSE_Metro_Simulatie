# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage"

# Include any dependencies generated for this target.
include CMakeFiles/MetroSimDebug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MetroSimDebug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MetroSimDebug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MetroSimDebug.dir/flags.make

CMakeFiles/MetroSimDebug.dir/main.cpp.obj: CMakeFiles/MetroSimDebug.dir/flags.make
CMakeFiles/MetroSimDebug.dir/main.cpp.obj: CMakeFiles/MetroSimDebug.dir/includes_CXX.rsp
CMakeFiles/MetroSimDebug.dir/main.cpp.obj: ../main.cpp
CMakeFiles/MetroSimDebug.dir/main.cpp.obj: CMakeFiles/MetroSimDebug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MetroSimDebug.dir/main.cpp.obj"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MetroSimDebug.dir/main.cpp.obj -MF CMakeFiles\MetroSimDebug.dir\main.cpp.obj.d -o CMakeFiles\MetroSimDebug.dir\main.cpp.obj -c "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\main.cpp"

CMakeFiles/MetroSimDebug.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetroSimDebug.dir/main.cpp.i"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\main.cpp" > CMakeFiles\MetroSimDebug.dir\main.cpp.i

CMakeFiles/MetroSimDebug.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetroSimDebug.dir/main.cpp.s"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\main.cpp" -o CMakeFiles\MetroSimDebug.dir\main.cpp.s

CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj: CMakeFiles/MetroSimDebug.dir/flags.make
CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj: CMakeFiles/MetroSimDebug.dir/includes_CXX.rsp
CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj: ../ParserTest.cpp
CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj: CMakeFiles/MetroSimDebug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj -MF CMakeFiles\MetroSimDebug.dir\ParserTest.cpp.obj.d -o CMakeFiles\MetroSimDebug.dir\ParserTest.cpp.obj -c "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\ParserTest.cpp"

CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.i"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\ParserTest.cpp" > CMakeFiles\MetroSimDebug.dir\ParserTest.cpp.i

CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.s"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\ParserTest.cpp" -o CMakeFiles\MetroSimDebug.dir\ParserTest.cpp.s

CMakeFiles/MetroSimDebug.dir/tests.cpp.obj: CMakeFiles/MetroSimDebug.dir/flags.make
CMakeFiles/MetroSimDebug.dir/tests.cpp.obj: CMakeFiles/MetroSimDebug.dir/includes_CXX.rsp
CMakeFiles/MetroSimDebug.dir/tests.cpp.obj: ../tests.cpp
CMakeFiles/MetroSimDebug.dir/tests.cpp.obj: CMakeFiles/MetroSimDebug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MetroSimDebug.dir/tests.cpp.obj"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MetroSimDebug.dir/tests.cpp.obj -MF CMakeFiles\MetroSimDebug.dir\tests.cpp.obj.d -o CMakeFiles\MetroSimDebug.dir\tests.cpp.obj -c "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\tests.cpp"

CMakeFiles/MetroSimDebug.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetroSimDebug.dir/tests.cpp.i"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\tests.cpp" > CMakeFiles\MetroSimDebug.dir\tests.cpp.i

CMakeFiles/MetroSimDebug.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetroSimDebug.dir/tests.cpp.s"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\tests.cpp" -o CMakeFiles\MetroSimDebug.dir\tests.cpp.s

# Object files for target MetroSimDebug
MetroSimDebug_OBJECTS = \
"CMakeFiles/MetroSimDebug.dir/main.cpp.obj" \
"CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj" \
"CMakeFiles/MetroSimDebug.dir/tests.cpp.obj"

# External object files for target MetroSimDebug
MetroSimDebug_EXTERNAL_OBJECTS =

MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/main.cpp.obj
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/ParserTest.cpp.obj
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/tests.cpp.obj
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/build.make
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/linklibs.rsp
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/objects1.rsp
MetroSimDebug.exe: CMakeFiles/MetroSimDebug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable MetroSimDebug.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MetroSimDebug.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MetroSimDebug.dir/build: MetroSimDebug.exe
.PHONY : CMakeFiles/MetroSimDebug.dir/build

CMakeFiles/MetroSimDebug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MetroSimDebug.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MetroSimDebug.dir/clean

CMakeFiles/MetroSimDebug.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie" "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie" "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage" "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage" "C:\Users\arne\Documents\2022-2023\s2\Talen En Automaten\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles\MetroSimDebug.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MetroSimDebug.dir/depend

