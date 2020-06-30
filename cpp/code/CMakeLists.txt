cmake_minimum_required(VERSION 3.8)
project(EnvironmentController.code CXX)
set(SOURCE_FILES
        EnvironmentController.cpp
        EnvironmentController.h
        Hardware.h)
add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

