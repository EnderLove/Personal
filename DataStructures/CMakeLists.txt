cmake_minimum_required(VERSION 3.10)
project(DataStructures VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB LIB_SOURCES "src/*.c")
add_library(ds_lib STATIC ${LIB_SOURCES})

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} ds_lib)

add_executable(addTwoNumbers problems/addTwoNumbers.c)
target_link_libraries(addTwoNumbers ds_lib)

if(MSVC)
    target_compile_options(ds_lib PRIVATE /W4)
    target_compile_options(addTwoNumbers PRIVATE /W4)
else()
    target_compile_options(ds_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(addTwoNumbers PRIVATE -Wall -Wextra -Wpedantic)
endif()
