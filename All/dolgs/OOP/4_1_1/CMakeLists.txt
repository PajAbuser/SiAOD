project(4_1_1)
cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

#[[set(CMAKE_BUILD_TYPE cmake-build-debug)
include(App.cpp)
include(Base.cpp)
include(Object.cpp)
include(App.h)
include(Base.h)
include(Object.h)]]

#[[target_include_directories()]]
set(SOURCES App.cpp Base.cpp Object.cpp App.h Base.h Object.h main.cpp)
add_executable(main ${SOURCES})
#[[set(SOURCE_EXE main.cpp)]]

#[[
add_executable(main main.cpp)]]
