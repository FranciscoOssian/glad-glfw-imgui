#ifndef LOOP_H  // Evita inclusões duplicadas
#define LOOP_H

#include <GLFW/glfw3.h>

#include <functional>

#include "imgui.h"

using WindowCloseCallback = std::function<void()>;

void loopWindowShouldClose(WindowCloseCallback callback, GLFWwindow *window,
                           ImGuiIO* io);

#endif
