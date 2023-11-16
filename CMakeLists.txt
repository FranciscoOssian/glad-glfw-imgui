# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(example_glfw_opengl3)

# Set ImGui directory
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/vendor/ImGUI)


# Glob source files
file(GLOB SOURCES
    src/main.cpp
    src/loop.cpp
    src/initialize.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Create executable with defined sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Set C++ standard to 11
set(CMAKE_CXX_STANDARD 11)

# Add glad submodule
add_subdirectory(vendor/glad)

# Add include directories
target_include_directories(
    example_glfw_opengl3 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Include ImGui directory and its subdirectories
include_directories(
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# Configure for OpenGL on Linux
if (UNIX AND NOT APPLE)
    set(LINUX_GL_LIBS -lGL)
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)
    include_directories(${GLFW_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${LINUX_GL_LIBS} ${GLFW_LIBRARIES} glad)
endif()

# Configure for OpenGL on macOS
if (APPLE)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" glfw glad)
endif()

# Configure for OpenGL on Windows
if (WIN32)
    find_package(glfw3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw glad)
endif()
