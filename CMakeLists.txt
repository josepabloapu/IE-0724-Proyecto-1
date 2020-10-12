cmake_minimum_required(VERSION 3.3)

# Project name and version
project(RBT VERSION 1.0)

# Add headers
include_directories(include)
set(CMAKE_BUILD_TYPE Release)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

############# SOURCES FOR EXECUTABLE ##########
# Add sources for executable
# set(SOURCES test/main.cpp src/rbt.cpp src/rbt_node.cpp)
file(GLOB SOURCES_EXE "src/*.cpp" "test/*.cpp")

add_compile_options("-W" "-Wall" "-pedantic")

# Add executable
add_executable(run_unittest ${SOURCES_EXE})

# Add GTest target link libraries to executable exe
target_link_libraries(run_unittest ${GTEST_LIBRARIES} pthread)

############# SOURCES FOR LIBRARY #############
# Add sources for shared library
file(GLOB SOURCES_LIB "src/*.cpp")

# Create library (.so)
# Change SHARED for STATIC to create static library (.a)
add_library(rbt SHARED ${SOURCES_LIB})

# Install library (.so)
install(TARGETS rbt DESTINATION /usr/lib/)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
