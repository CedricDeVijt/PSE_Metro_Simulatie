# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/testing_tool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testing_tool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testing_tool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testing_tool.dir/flags.make

CMakeFiles/testing_tool.dir/tst/main.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tst/main.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tst/main.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tst/main.cpp
CMakeFiles/testing_tool.dir/tst/main.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testing_tool.dir/tst/main.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tst/main.cpp.obj -MF CMakeFiles\testing_tool.dir\tst\main.cpp.obj.d -o CMakeFiles\testing_tool.dir\tst\main.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\main.cpp

CMakeFiles/testing_tool.dir/tst/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tst/main.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\main.cpp > CMakeFiles\testing_tool.dir\tst\main.cpp.i

CMakeFiles/testing_tool.dir/tst/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tst/main.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\main.cpp -o CMakeFiles\testing_tool.dir\tst\main.cpp.s

CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tst/ParserTest.cpp
CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj -MF CMakeFiles\testing_tool.dir\tst\ParserTest.cpp.obj.d -o CMakeFiles\testing_tool.dir\tst\ParserTest.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\ParserTest.cpp

CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\ParserTest.cpp > CMakeFiles\testing_tool.dir\tst\ParserTest.cpp.i

CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tst\ParserTest.cpp -o CMakeFiles\testing_tool.dir\tst\ParserTest.cpp.s

CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/MetroSimulation.cpp
CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj -MF CMakeFiles\testing_tool.dir\src\MetroSimulation.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\MetroSimulation.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroSimulation.cpp

CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroSimulation.cpp > CMakeFiles\testing_tool.dir\src\MetroSimulation.cpp.i

CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroSimulation.cpp -o CMakeFiles\testing_tool.dir\src\MetroSimulation.cpp.s

CMakeFiles/testing_tool.dir/src/Station.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/Station.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/Station.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/Station.cpp
CMakeFiles/testing_tool.dir/src/Station.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testing_tool.dir/src/Station.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/Station.cpp.obj -MF CMakeFiles\testing_tool.dir\src\Station.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\Station.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Station.cpp

CMakeFiles/testing_tool.dir/src/Station.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/Station.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Station.cpp > CMakeFiles\testing_tool.dir\src\Station.cpp.i

CMakeFiles/testing_tool.dir/src/Station.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/Station.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Station.cpp -o CMakeFiles\testing_tool.dir\src\Station.cpp.s

CMakeFiles/testing_tool.dir/src/Tram.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/Tram.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/Tram.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/Tram.cpp
CMakeFiles/testing_tool.dir/src/Tram.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/testing_tool.dir/src/Tram.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/Tram.cpp.obj -MF CMakeFiles\testing_tool.dir\src\Tram.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\Tram.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Tram.cpp

CMakeFiles/testing_tool.dir/src/Tram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/Tram.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Tram.cpp > CMakeFiles\testing_tool.dir\src\Tram.cpp.i

CMakeFiles/testing_tool.dir/src/Tram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/Tram.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Tram.cpp -o CMakeFiles\testing_tool.dir\src\Tram.cpp.s

CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/MetroXMLParser.cpp
CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj -MF CMakeFiles\testing_tool.dir\src\MetroXMLParser.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\MetroXMLParser.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroXMLParser.cpp

CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroXMLParser.cpp > CMakeFiles\testing_tool.dir\src\MetroXMLParser.cpp.i

CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\MetroXMLParser.cpp -o CMakeFiles\testing_tool.dir\src\MetroXMLParser.cpp.s

CMakeFiles/testing_tool.dir/src/Track.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/Track.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/Track.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/Track.cpp
CMakeFiles/testing_tool.dir/src/Track.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/testing_tool.dir/src/Track.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/Track.cpp.obj -MF CMakeFiles\testing_tool.dir\src\Track.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\Track.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Track.cpp

CMakeFiles/testing_tool.dir/src/Track.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/Track.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Track.cpp > CMakeFiles\testing_tool.dir\src\Track.cpp.i

CMakeFiles/testing_tool.dir/src/Track.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/Track.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Track.cpp -o CMakeFiles\testing_tool.dir\src\Track.cpp.s

CMakeFiles/testing_tool.dir/src/Line.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/src/Line.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/src/Line.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/src/Line.cpp
CMakeFiles/testing_tool.dir/src/Line.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/testing_tool.dir/src/Line.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/src/Line.cpp.obj -MF CMakeFiles\testing_tool.dir\src\Line.cpp.obj.d -o CMakeFiles\testing_tool.dir\src\Line.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Line.cpp

CMakeFiles/testing_tool.dir/src/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/src/Line.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Line.cpp > CMakeFiles\testing_tool.dir\src\Line.cpp.i

CMakeFiles/testing_tool.dir/src/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/src/Line.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\src\Line.cpp -o CMakeFiles\testing_tool.dir\src\Line.cpp.s

CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tinyxml/tinystr.cpp
CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj -MF CMakeFiles\testing_tool.dir\tinyxml\tinystr.cpp.obj.d -o CMakeFiles\testing_tool.dir\tinyxml\tinystr.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinystr.cpp

CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinystr.cpp > CMakeFiles\testing_tool.dir\tinyxml\tinystr.cpp.i

CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinystr.cpp -o CMakeFiles\testing_tool.dir\tinyxml\tinystr.cpp.s

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tinyxml/tinyxmlerror.cpp
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj -MF CMakeFiles\testing_tool.dir\tinyxml\tinyxmlerror.cpp.obj.d -o CMakeFiles\testing_tool.dir\tinyxml\tinyxmlerror.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlerror.cpp

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlerror.cpp > CMakeFiles\testing_tool.dir\tinyxml\tinyxmlerror.cpp.i

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlerror.cpp -o CMakeFiles\testing_tool.dir\tinyxml\tinyxmlerror.cpp.s

CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tinyxml/tinyxml.cpp
CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj -MF CMakeFiles\testing_tool.dir\tinyxml\tinyxml.cpp.obj.d -o CMakeFiles\testing_tool.dir\tinyxml\tinyxml.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxml.cpp

CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxml.cpp > CMakeFiles\testing_tool.dir\tinyxml\tinyxml.cpp.i

CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxml.cpp -o CMakeFiles\testing_tool.dir\tinyxml\tinyxml.cpp.s

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj: CMakeFiles/testing_tool.dir/flags.make
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj: CMakeFiles/testing_tool.dir/includes_CXX.rsp
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj: C:/Users/arne/Documents/2022-2023/s2/PSE/PSE_Metro_Simulatie/tinyxml/tinyxmlparser.cpp
CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj: CMakeFiles/testing_tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj -MF CMakeFiles\testing_tool.dir\tinyxml\tinyxmlparser.cpp.obj.d -o CMakeFiles\testing_tool.dir\tinyxml\tinyxmlparser.cpp.obj -c C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlparser.cpp

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlparser.cpp > CMakeFiles\testing_tool.dir\tinyxml\tinyxmlparser.cpp.i

CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\tinyxml\tinyxmlparser.cpp -o CMakeFiles\testing_tool.dir\tinyxml\tinyxmlparser.cpp.s

# Object files for target testing_tool
testing_tool_OBJECTS = \
"CMakeFiles/testing_tool.dir/tst/main.cpp.obj" \
"CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/Station.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/Tram.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/Track.cpp.obj" \
"CMakeFiles/testing_tool.dir/src/Line.cpp.obj" \
"CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj" \
"CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj" \
"CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj" \
"CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj"

# External object files for target testing_tool
testing_tool_EXTERNAL_OBJECTS =

testing_tool.exe: CMakeFiles/testing_tool.dir/tst/main.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/tst/ParserTest.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/MetroSimulation.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/Station.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/Tram.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/MetroXMLParser.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/Track.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/src/Line.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/tinyxml/tinystr.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/tinyxml/tinyxmlerror.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/tinyxml/tinyxml.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/tinyxml/tinyxmlparser.cpp.obj
testing_tool.exe: CMakeFiles/testing_tool.dir/build.make
testing_tool.exe: CMakeFiles/testing_tool.dir/linklibs.rsp
testing_tool.exe: CMakeFiles/testing_tool.dir/objects1.rsp
testing_tool.exe: CMakeFiles/testing_tool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable testing_tool.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testing_tool.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testing_tool.dir/build: testing_tool.exe
.PHONY : CMakeFiles/testing_tool.dir/build

CMakeFiles/testing_tool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testing_tool.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testing_tool.dir/clean

CMakeFiles/testing_tool.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage C:\Users\arne\Documents\2022-2023\s2\PSE\PSE_Metro_Simulatie\cmake-build-debug-coverage\CMakeFiles\testing_tool.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testing_tool.dir/depend

