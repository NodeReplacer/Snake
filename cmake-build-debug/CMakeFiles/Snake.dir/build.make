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
CMAKE_COMMAND = "G:\Program Files\JetBrains\CLion 2022.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Program Files\JetBrains\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\Personal Projects\C++ Projects\Snake"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\Personal Projects\C++ Projects\Snake\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Snake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Snake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Snake.dir/flags.make

CMakeFiles/Snake.dir/main.cpp.obj: CMakeFiles/Snake.dir/flags.make
CMakeFiles/Snake.dir/main.cpp.obj: CMakeFiles/Snake.dir/includes_CXX.rsp
CMakeFiles/Snake.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Snake.dir/main.cpp.obj: CMakeFiles/Snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Personal Projects\C++ Projects\Snake\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Snake.dir/main.cpp.obj"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Snake.dir/main.cpp.obj -MF CMakeFiles\Snake.dir\main.cpp.obj.d -o CMakeFiles\Snake.dir\main.cpp.obj -c "G:\Personal Projects\C++ Projects\Snake\main.cpp"

CMakeFiles/Snake.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snake.dir/main.cpp.i"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Personal Projects\C++ Projects\Snake\main.cpp" > CMakeFiles\Snake.dir\main.cpp.i

CMakeFiles/Snake.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snake.dir/main.cpp.s"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\Personal Projects\C++ Projects\Snake\main.cpp" -o CMakeFiles\Snake.dir\main.cpp.s

CMakeFiles/Snake.dir/Game.cpp.obj: CMakeFiles/Snake.dir/flags.make
CMakeFiles/Snake.dir/Game.cpp.obj: CMakeFiles/Snake.dir/includes_CXX.rsp
CMakeFiles/Snake.dir/Game.cpp.obj: ../Game.cpp
CMakeFiles/Snake.dir/Game.cpp.obj: CMakeFiles/Snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Personal Projects\C++ Projects\Snake\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Snake.dir/Game.cpp.obj"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Snake.dir/Game.cpp.obj -MF CMakeFiles\Snake.dir\Game.cpp.obj.d -o CMakeFiles\Snake.dir\Game.cpp.obj -c "G:\Personal Projects\C++ Projects\Snake\Game.cpp"

CMakeFiles/Snake.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snake.dir/Game.cpp.i"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Personal Projects\C++ Projects\Snake\Game.cpp" > CMakeFiles\Snake.dir\Game.cpp.i

CMakeFiles/Snake.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snake.dir/Game.cpp.s"
	G:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "G:\Personal Projects\C++ Projects\Snake\Game.cpp" -o CMakeFiles\Snake.dir\Game.cpp.s

# Object files for target Snake
Snake_OBJECTS = \
"CMakeFiles/Snake.dir/main.cpp.obj" \
"CMakeFiles/Snake.dir/Game.cpp.obj"

# External object files for target Snake
Snake_EXTERNAL_OBJECTS =

Snake.exe: CMakeFiles/Snake.dir/main.cpp.obj
Snake.exe: CMakeFiles/Snake.dir/Game.cpp.obj
Snake.exe: CMakeFiles/Snake.dir/build.make
Snake.exe: ../SFML/lib/libsfml-system-s-d.a
Snake.exe: ../SFML/lib/libsfml-window-s-d.a
Snake.exe: ../SFML/lib/libsfml-graphics-s-d.a
Snake.exe: ../SFML/lib/libsfml-audio-s-d.a
Snake.exe: ../SFML/lib/libsfml-window-s-d.a
Snake.exe: ../SFML/lib/libfreetype.a
Snake.exe: ../SFML/lib/libsfml-system-s-d.a
Snake.exe: ../SFML/lib/libopenal32.a
Snake.exe: ../SFML/lib/libvorbisfile.a
Snake.exe: ../SFML/lib/libvorbisenc.a
Snake.exe: ../SFML/lib/libvorbis.a
Snake.exe: ../SFML/lib/libogg.a
Snake.exe: ../SFML/lib/libFLAC.a
Snake.exe: CMakeFiles/Snake.dir/linklibs.rsp
Snake.exe: CMakeFiles/Snake.dir/objects1.rsp
Snake.exe: CMakeFiles/Snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\Personal Projects\C++ Projects\Snake\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Snake.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Snake.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Snake.dir/build: Snake.exe
.PHONY : CMakeFiles/Snake.dir/build

CMakeFiles/Snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Snake.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Snake.dir/clean

CMakeFiles/Snake.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "G:\Personal Projects\C++ Projects\Snake" "G:\Personal Projects\C++ Projects\Snake" "G:\Personal Projects\C++ Projects\Snake\cmake-build-debug" "G:\Personal Projects\C++ Projects\Snake\cmake-build-debug" "G:\Personal Projects\C++ Projects\Snake\cmake-build-debug\CMakeFiles\Snake.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Snake.dir/depend

