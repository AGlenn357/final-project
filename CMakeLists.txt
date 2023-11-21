# CMakeList.txt : CMake project for Final_Project, include source and define

# Add source to this project's executable.
#include all header files in the current folder

cmake_minimum_required(VERSION 3.2) # Specify CMake version.
project(424_Final_Project) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/lib/SDL)
add_executable(${CMAKE_PROJECT_NAME} "Final_Project.cpp" "Final_Project.h" "logo.h" "Pilot.cpp" "Pilot.h" "Copilot.cpp" "Copilot.h" "Plane.cpp" "Plane.h" "Racing_Game.cpp" "Racing_Game.h")

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/SDL2d.lib ${CMAKE_SOURCE_DIR}/lib/SDL2maind.lib)
set_target_properties( ${CMAKE_PROJECT_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")


# Copy the dynamic library to the same folder as the executable file.
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD # Adds a post-build event to MyTest
COMMAND ${CMAKE_COMMAND} -E copy_if_different # which executes "cmake - E copy_if_different..."
"${CMAKE_SOURCE_DIR}/lib/SDL2d.dll" # <--this is in- file
$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>) # <--this is out-file path


# target_link_libraries(${CMAKE_PROJECT_NAME} "${CMAKE_SOURCE_DIR}/lib/SDL2d.lib;${CMAKE_SOURCE_DIR}/lib/SDL2maind.lib")

# "${CMAKE_SOURCE_DIR}/map.bmp" # <--this is also in-file
