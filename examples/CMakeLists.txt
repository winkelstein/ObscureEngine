cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(ObscureEngineExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ [binary_dir])

file(GLOB
    SOURCE_FILES "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ObscureEngine)