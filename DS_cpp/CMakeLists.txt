cmake_minimum_required(VERSION 3.10)
project(DataStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
enable_testing()

file(GLOB LIB_SOURCES "src/*.cpp")
add_library(ds_lib STATIC ${LIB_SOURCES})

file(GLOB TEST_FILES "test/*.cpp")

foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${tset_name} ds_lib)

    add_test(NAME ${test_name} COMMAND ${test_name})

    message(STATUS "CREATED TEST TARGET : ${test_name}")
endforeach()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ds_lib)

if(MSVC)
    target_compile_options(ds_lib PRIVATE /W4)
else()
    target_compile_options(ds_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()
