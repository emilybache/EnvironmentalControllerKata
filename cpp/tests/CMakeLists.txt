cmake_minimum_required(VERSION 3.8)
set(TEST_NAME EnvironmentController.tests)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        PlainCatch2ExampleTest.cpp
        HardwareStub.cpp HardwareStub.h BobsDSLExampleTest.cpp ApprovalsExampleTest.cpp)
add_executable(${TEST_NAME} ${SOURCE_FILES})
find_library(EnvironmentController.code code ../code)
target_link_libraries(${TEST_NAME} LINK_PUBLIC EnvironmentController.code)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

