cmake_minimum_required(VERSION 3.0)

set(SRC_PATH /home/ultimatepandit/eclipse-workspace/FlamingoRunner)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAG "${CMAKE_CXX_FLAG} -std=c++14")


project(FlamingoRunner)

add_executable(
        flamingorunner
	src/FlamingoRunner.cpp
)
