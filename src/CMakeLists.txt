cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAG "${CMAKE_CXX_FLAG} -std=c++14")


project(FlamingoRunner)

add_executable(
	flamingorunner
	FlamingoRunner.cpp
)

