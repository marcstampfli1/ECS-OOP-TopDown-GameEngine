# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build

# Include any dependencies generated for this target.
include CMakeFiles/MyRPGEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyRPGEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyRPGEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyRPGEngine.dir/flags.make

CMakeFiles/MyRPGEngine.dir/codegen:
.PHONY : CMakeFiles/MyRPGEngine.dir/codegen

CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/main.cpp
CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\main.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\main.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\main.cpp

CMakeFiles/MyRPGEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\main.cpp > CMakeFiles\MyRPGEngine.dir\src\main.cpp.i

CMakeFiles/MyRPGEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\main.cpp -o CMakeFiles\MyRPGEngine.dir\src\main.cpp.s

CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/Behaviours.cpp
CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\Behaviours.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\Behaviours.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Behaviours.cpp

CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Behaviours.cpp > CMakeFiles\MyRPGEngine.dir\src\Behaviours.cpp.i

CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Behaviours.cpp -o CMakeFiles\MyRPGEngine.dir\src\Behaviours.cpp.s

CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/Component.cpp
CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\Component.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\Component.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Component.cpp

CMakeFiles/MyRPGEngine.dir/src/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/Component.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Component.cpp > CMakeFiles\MyRPGEngine.dir\src\Component.cpp.i

CMakeFiles/MyRPGEngine.dir/src/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/Component.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Component.cpp -o CMakeFiles\MyRPGEngine.dir\src\Component.cpp.s

CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/Entity.cpp
CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\Entity.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\Entity.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Entity.cpp

CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Entity.cpp > CMakeFiles\MyRPGEngine.dir\src\Entity.cpp.i

CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Entity.cpp -o CMakeFiles\MyRPGEngine.dir\src\Entity.cpp.s

CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/Render.cpp
CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\Render.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\Render.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Render.cpp

CMakeFiles/MyRPGEngine.dir/src/Render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/Render.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Render.cpp > CMakeFiles\MyRPGEngine.dir\src\Render.cpp.i

CMakeFiles/MyRPGEngine.dir/src/Render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/Render.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Render.cpp -o CMakeFiles\MyRPGEngine.dir\src\Render.cpp.s

CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/ResourceManager.cpp
CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\ResourceManager.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\ResourceManager.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\ResourceManager.cpp

CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\ResourceManager.cpp > CMakeFiles\MyRPGEngine.dir\src\ResourceManager.cpp.i

CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\ResourceManager.cpp -o CMakeFiles\MyRPGEngine.dir\src\ResourceManager.cpp.s

CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj: CMakeFiles/MyRPGEngine.dir/flags.make
CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj: CMakeFiles/MyRPGEngine.dir/includes_CXX.rsp
CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/src/Systems.cpp
CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj: CMakeFiles/MyRPGEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj -MF CMakeFiles\MyRPGEngine.dir\src\Systems.cpp.obj.d -o CMakeFiles\MyRPGEngine.dir\src\Systems.cpp.obj -c C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Systems.cpp

CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Systems.cpp > CMakeFiles\MyRPGEngine.dir\src\Systems.cpp.i

CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\src\Systems.cpp -o CMakeFiles\MyRPGEngine.dir\src\Systems.cpp.s

# Object files for target MyRPGEngine
MyRPGEngine_OBJECTS = \
"CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj" \
"CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj"

# External object files for target MyRPGEngine
MyRPGEngine_EXTERNAL_OBJECTS =

MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/main.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/Behaviours.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/Component.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/Entity.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/Render.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/ResourceManager.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/src/Systems.cpp.obj
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/build.make
MyRPGEngine.exe: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/graphicslib/build/libgraphicslib.a
MyRPGEngine.exe: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/graphicslib/libraries/lib/libglfw3.a
MyRPGEngine.exe: C:/Users/ur2ba/OneDrive/Desktop/ECS-OOP-TopDown-GameEngine/graphicslib/libraries/lib/libglad.a
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/linkLibs.rsp
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/objects1.rsp
MyRPGEngine.exe: CMakeFiles/MyRPGEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable MyRPGEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyRPGEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyRPGEngine.dir/build: MyRPGEngine.exe
.PHONY : CMakeFiles/MyRPGEngine.dir/build

CMakeFiles/MyRPGEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyRPGEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyRPGEngine.dir/clean

CMakeFiles/MyRPGEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build C:\Users\ur2ba\OneDrive\Desktop\ECS-OOP-TopDown-GameEngine\build\CMakeFiles\MyRPGEngine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyRPGEngine.dir/depend

