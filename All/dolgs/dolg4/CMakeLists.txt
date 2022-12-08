project(dolg3)

set(SOURCE_EXE main.cpp . MyH.h)
set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp MyH.h)

add_executable(main ${SOURCES})