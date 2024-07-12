cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(ObscureEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-Wall" "-Werror" "-Wextra" "-fsanitize=undefined,address")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

file(GLOB
    SOURCE_FILES "src/*.cpp")
add_library(ObscureEngine SHARED ${SOURCE_FILES})

find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
endif(APPLE)

target_link_libraries(${PROJECT_NAME} glfw ${OPENGL_gl_LIBRARY})