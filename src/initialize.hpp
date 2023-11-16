#ifndef INITIALIZE_H

#define INITIALIZE_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "loop.hpp"

bool initialize(GLFWwindow *&window, const char *glsl_version, ImGuiIO &io);

#endif