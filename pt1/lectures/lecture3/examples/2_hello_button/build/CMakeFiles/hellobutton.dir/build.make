# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build

# Include any dependencies generated for this target.
include CMakeFiles/hellobutton.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hellobutton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellobutton.dir/flags.make

CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o: CMakeFiles/hellobutton.dir/flags.make
CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o: hellobutton_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o -c /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/hellobutton_autogen/mocs_compilation.cpp

CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/hellobutton_autogen/mocs_compilation.cpp > CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.i

CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/hellobutton_autogen/mocs_compilation.cpp -o CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.s

CMakeFiles/hellobutton.dir/helloform.cpp.o: CMakeFiles/hellobutton.dir/flags.make
CMakeFiles/hellobutton.dir/helloform.cpp.o: ../helloform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hellobutton.dir/helloform.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hellobutton.dir/helloform.cpp.o -c /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/helloform.cpp

CMakeFiles/hellobutton.dir/helloform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellobutton.dir/helloform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/helloform.cpp > CMakeFiles/hellobutton.dir/helloform.cpp.i

CMakeFiles/hellobutton.dir/helloform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellobutton.dir/helloform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/helloform.cpp -o CMakeFiles/hellobutton.dir/helloform.cpp.s

CMakeFiles/hellobutton.dir/main.cpp.o: CMakeFiles/hellobutton.dir/flags.make
CMakeFiles/hellobutton.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hellobutton.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hellobutton.dir/main.cpp.o -c /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/main.cpp

CMakeFiles/hellobutton.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellobutton.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/main.cpp > CMakeFiles/hellobutton.dir/main.cpp.i

CMakeFiles/hellobutton.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellobutton.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/main.cpp -o CMakeFiles/hellobutton.dir/main.cpp.s

# Object files for target hellobutton
hellobutton_OBJECTS = \
"CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/hellobutton.dir/helloform.cpp.o" \
"CMakeFiles/hellobutton.dir/main.cpp.o"

# External object files for target hellobutton
hellobutton_EXTERNAL_OBJECTS =

hellobutton: CMakeFiles/hellobutton.dir/hellobutton_autogen/mocs_compilation.cpp.o
hellobutton: CMakeFiles/hellobutton.dir/helloform.cpp.o
hellobutton: CMakeFiles/hellobutton.dir/main.cpp.o
hellobutton: CMakeFiles/hellobutton.dir/build.make
hellobutton: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
hellobutton: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
hellobutton: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
hellobutton: CMakeFiles/hellobutton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable hellobutton"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellobutton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellobutton.dir/build: hellobutton

.PHONY : CMakeFiles/hellobutton.dir/build

CMakeFiles/hellobutton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hellobutton.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hellobutton.dir/clean

CMakeFiles/hellobutton.dir/depend:
	cd /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build /home/anna/students/cpp/pt1/lectures/lecture3/examples/2_hello_button/build/CMakeFiles/hellobutton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hellobutton.dir/depend

