cmake_minimum_required(VERSION 3.10)
project(MyRPGEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/src/headers)

# ✅ Collect all source files
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

# ✅ Ensure headers are available
include_directories(${HEADERS_DIR})

# ✅ Create `MyRPGEngine` as a static library
add_library(MyRPGEngine STATIC ${SOURCES})

# --------------------------------
# **DEPENDENCIES (builtgraphicslib & soloud)**
# --------------------------------

# ✅ **Include directories (ONLY required for headers)**
target_include_directories(MyRPGEngine PRIVATE 
    ${CMAKE_SOURCE_DIR}/builtgraphicslib/include  # ✅ Ensures `graphicslib` headers are found
    ${CMAKE_SOURCE_DIR}/soloud/include            # ✅ Ensures `soloud.h` is found
)

# ✅ **Tell CMake Where to Find `.a` Files**
target_link_directories(MyRPGEngine PRIVATE 
    ${CMAKE_SOURCE_DIR}/builtgraphicslib/lib      # ✅ Contains `libgraphicslib.a`
    ${CMAKE_SOURCE_DIR}/soloud/lib                # ✅ Contains `libsoloud.a`
)

# ✅ **Only Link `libgraphicslib.a` and `libsoloud.a`**
target_link_libraries(MyRPGEngine PRIVATE 
    ${CMAKE_SOURCE_DIR}/builtgraphicslib/lib/libgraphicslib.a
    ${CMAKE_SOURCE_DIR}/soloud/lib/libsoloud.a
)

# ✅ **Make sure static library is output to `lib/`**
set_target_properties(MyRPGEngine PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ✅ **Fix for Windows**
if (WIN32)
    target_link_libraries(MyRPGEngine PRIVATE winmm gdi32)
endif()

# --------------------------------
# **BUILD THE EXECUTABLE**
# --------------------------------

set(MAIN_SRC ${SRC_DIR}/main.cpp)

# ✅ **Ensure `MyRPGEngine.a` is Built Before `MyRPGGame.exe`**
add_executable(MyRPGGame ${MAIN_SRC})
add_dependencies(MyRPGGame MyRPGEngine)  # ✅ This ensures `MyRPGEngine.a` is created first.

# ✅ **Include directories for executable**
target_include_directories(MyRPGGame PRIVATE 
    ${CMAKE_SOURCE_DIR}/builtgraphicslib/include  # ✅ Ensures `graphicslib` headers are found
    ${CMAKE_SOURCE_DIR}/soloud/include            # ✅ Ensures `soloud.h` is found
)

# ✅ **Use `MyRPGEngine` as a Target Instead of Hardcoding `.a` Paths**
target_link_libraries(MyRPGGame PRIVATE MyRPGEngine)
