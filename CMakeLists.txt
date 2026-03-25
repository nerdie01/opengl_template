cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME OpenGLTemplate)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(SOURCES
    "src/main.cpp"
    "src/glad/gl.c"
)

set(LIBRARIES
    "glfw"
    "OpenGL::GL")

add_subdirectory("lib/glfw")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})